#include "SDL_Framework.h"

using namespace std;

bool SDL_Framework::Init()
{
    int result = SDL_Init(SDL_INIT_EVERYTHING);
    if (result != 0) {
        std::cout << "SDL_Init failed, result: " << result << ".\n";
        std::getchar();
        return false;
    }
    if (window_x_ == -1 || window_y_ == -1) {
        SDL_DisplayMode display_mode;
        SDL_GetCurrentDisplayMode(0, &display_mode);
        if (window_x_ == -1)
            window_x_ = (display_mode.w - window_width_) / 2;
        if (window_y_ == -1)
            window_y_ = (display_mode.h - window_height_) / 2;
    }
    window_ = SDL_CreateWindow(window_title_, window_x_, window_y_, window_width_, window_height_, window_flags_);
    if (window_ == 0) {
        std::cout << "SDL_CreateWindow failed.\n";
        std::getchar();
        return false;
    }
    SDL_GetWindowSize(window_, &window_width_, &window_height_);
    renderer_ = SDL_CreateRenderer(window_, -1, 0);
    if (renderer_ == 0) {
        std::cout << "SDL_CreateRenderer failed.\n";
        std::getchar();
        return false;
    }
    is_running_ = UserInit();
    return is_running_;
}

void SDL_Framework::Run()
{
    Uint32 start_time = SDL_GetTicks();
    Uint32 timer = start_time;
    int local_frame_count = 0;

    while (is_running_) {
        Uint32 frame_start = SDL_GetTicks();
        Uint32 elapsed_time = frame_start - start_time;
        start_time = frame_start;

        HandleEvents();
        if (!UserRender(elapsed_time)) {
            is_running_ = false;
        }
        SDL_RenderPresent(Renderer());
        ResetMatrix();

        local_frame_count++;
        global_frame_count_++;
        if (SDL_GetTicks() - timer > 1000) {
            std::string t = window_title_;
            t.append(" (");
            t.append(std::to_string(local_frame_count));
            t.append(" FPS)");
            SDL_SetWindowTitle(window_, t.c_str());
            timer += 1000;
            local_frame_count = 0;
        }

        Uint32 frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < kMaxFrameTime) {
            SDL_Delay((int)(kMaxFrameTime - frame_time));
        }
    }

    UserClean();

    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
}

void SDL_Framework::DrawCircle(int center_x, int center_y, int diameter, SDL_Color color, bool fill)
{
    double sin_value = sin(rotation_radians_);
    double cos_value = cos(rotation_radians_);

    double rotated_x1 = center_x * cos_value - center_y * sin_value;
    double rotated_y1 = center_x * sin_value + center_y * cos_value;

    int final_x1 = static_cast<int>(rotated_x1 + origin_x_);
    int final_y1 = static_cast<int>(rotated_y1 + origin_y_);

    auto radius = diameter / 2;
    auto radius2 = radius * radius;
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    for (int w = 0; w <= diameter; w++) {
        for (int h = 0; h <= diameter; h++) {
            int dx = radius - w;
            int dy = radius - h;
            int pos = dx * dx + dy * dy;
            if (fill && pos <= radius2) {
                SDL_RenderDrawPoint(renderer_, final_x1 + dx, final_y1 + dy);
            }
            int diff = pos - radius2;
            if (!fill && abs(diff) <= 10) {
                SDL_RenderDrawPoint(renderer_, final_x1 + dx, final_y1 + dy);
            }
        }
    }
}

void SDL_Framework::DrawRectangle(int x, int y, int width, int height, SDL_Color color)
{
    std::vector<SDL_Point> corner = {
        {x, y},
        {x + width, y},
        {x + width, y + height},
        {x, y + height}
    };
    auto center_x = x + width / 2;
    auto center_y = y + height / 2;
    double sin = std::sin(rotation_radians_);
    double cos = std::cos(rotation_radians_);
    for (int i = 0; i < 4; i++) {
        corner[i].x -= center_x;
        corner[i].y -= center_y;
        double x_new = corner[i].x * cos - corner[i].y * sin;
        double y_new = corner[i].x * sin + corner[i].y * cos;
        corner[i].x = static_cast<int>(x_new + center_x);
        corner[i].y = static_cast<int>(y_new + center_y);
    }
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    for (int i = 0; i < 4; i++) {
        auto next = (i + 1) % 4;
        auto x1 = corner[i].x + origin_x_;
        auto y1 = corner[i].y + origin_y_;
        auto x2 = corner[next].x + origin_x_;
        auto y2 = corner[next].y + origin_y_;
        SDL_RenderDrawLine(renderer_, x1, y1, x2, y2);
    }
}

void SDL_Framework::DrawLine(int x1, int y1, int x2, int y2, SDL_Color color)
{
    double sin_value = sin(rotation_radians_);
    double cos_value = cos(rotation_radians_);

    double rotated_x1 = x1 * cos_value - y1 * sin_value;
    double rotated_y1 = x1 * sin_value + y1 * cos_value;
    double rotated_x2 = x2 * cos_value - y2 * sin_value;
    double rotated_y2 = x2 * sin_value + y2 * cos_value;

    int final_x1 = static_cast<int>(rotated_x1 + origin_x_);
    int final_y1 = static_cast<int>(rotated_y1 + origin_y_);
    int final_x2 = static_cast<int>(rotated_x2 + origin_x_);
    int final_y2 = static_cast<int>(rotated_y2 + origin_y_);

    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer_, final_x1, final_y1, final_x2, final_y2);
}

void SDL_Framework::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            {
                auto found = std::find(pressed_keys_.begin(), pressed_keys_.end(), event.key.keysym.sym);
                if (found == pressed_keys_.end()) {
                    pressed_keys_.push_back(event.key.keysym.sym);
                }
            }
            break;
        case SDL_KEYUP:
            pressed_keys_.remove(event.key.keysym.sym);
            break;
        case SDL_QUIT:
            is_running_ = false;
            break;
        case SDL_MOUSEMOTION:
            mouse_position_.x = event.motion.x;
            mouse_position_.y = event.motion.y;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
                mouse_button_states_[kMouseLeftButton] = true;
            if (event.button.button == SDL_BUTTON_MIDDLE)
                mouse_button_states_[kMouseMiddleButton] = true;
            if (event.button.button == SDL_BUTTON_RIGHT)
                mouse_button_states_[kMouseRightButton] = true;
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
                mouse_button_states_[kMouseLeftButton] = false;
            if (event.button.button == SDL_BUTTON_MIDDLE)
                mouse_button_states_[kMouseMiddleButton] = false;
            if (event.button.button == SDL_BUTTON_RIGHT)
                mouse_button_states_[kMouseRightButton] = false;
            break;
        default:
            break;
        }
    }
}

bool SDL_Framework::IsKeyPressed(Sint32 key)
{
    return std::find(pressed_keys_.begin(), pressed_keys_.end(), key) != pressed_keys_.end();
}

void SDL_Framework::ClearScreen(void)
{
    SDL_SetRenderDrawColor(Renderer(), kColorWhite.r, kColorWhite.g, kColorWhite.b, 255);
    SDL_RenderClear(Renderer());
}

//END

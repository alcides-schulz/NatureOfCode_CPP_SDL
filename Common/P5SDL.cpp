#include "P5SDL.h"

using namespace std;

bool P5SDL::Init()
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
    SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);
    for (int degree = 0; degree < 360; degree++) {
        circle_cos_cache[degree] = (double)cos(degree * M_PI / 180);
        circle_sin_cache[degree] = (double)sin(degree * M_PI / 180);
    }
    is_running_ = Setup();
    if (!is_running_) {
        SDL_DestroyWindow(window_);
        SDL_DestroyRenderer(renderer_);
        SDL_Quit();
    }
    return is_running_;
}

void P5SDL::Run()
{
    Uint32 start_time = SDL_GetTicks();
    Uint32 timer = start_time;
    int local_frame_count = 0;

    while (is_running_) {
        Uint32 frame_start = SDL_GetTicks();
        Uint32 elapsed_time = frame_start - start_time;
        start_time = frame_start;

        HandleEvents();
        if (!Draw()) {
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

    Cleanup();

    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
}

void P5SDL::Circle(float center_x, float center_y, int diameter)
{
    Circle((int)center_x, (int)center_y, diameter);
}

void P5SDL::Circle(int center_x, int center_y, int diameter)
{
    // Translate and rotate circle position
    double sin_value = sin(rotation_radians_);
    double cos_value = cos(rotation_radians_);
    double rotated_x = center_x * cos_value - center_y * sin_value;
    double rotated_y = center_x * sin_value + center_y * cos_value;
    int final_x = static_cast<int>(rotated_x + origin_x_);
    int final_y = static_cast<int>(rotated_y + origin_y_);
    // Fill in
    if (fill_color_.r != background_color_.r || fill_color_.g != background_color_.g || fill_color_.b != background_color_.b || fill_color_.a != background_color_.a) {
        auto radius = diameter / 2;
        auto radius2 = radius * radius;
        SDL_SetRenderDrawColor(renderer_, fill_color_.r, fill_color_.g, fill_color_.b, fill_color_.a);
        for (int y = -radius; y <= radius; y++) {
            int maxX = (int)(sqrt(radius2 - y * y));
            SDL_RenderDrawLine(renderer_, final_x - maxX, final_y + y, final_x + maxX, final_y + y);
        }
    }
    // Draw circle
    SDL_SetRenderDrawColor(renderer_, stroke_color_.r, stroke_color_.g, stroke_color_.b, stroke_color_.a);
    for (int thickness = 0; thickness < stroke_weight_; thickness++) {
        auto radius = diameter / 2 - thickness;
        for (int degree = 0; degree < 360; degree++) {
            int x = (int)(final_x + radius * circle_cos_cache[degree]); //cos(degree * M_PI / 180)
            int y = (int)(final_y + radius * circle_sin_cache[degree]); //sin(degree * M_PI / 180)
            SDL_RenderDrawPoint(renderer_, x, y);
        }
    }
}

void P5SDL::Rect(int x, int y, int width, int height)
{
    std::vector<SDL_Point> corner = {
        {x, y},
        {x + width, y},
        {x + width, y + height},
        {x, y + height}
    };
    if (rect_mode_ == kRectCorner) {
        for (int i = 0; i < 4; i++) {
            auto next = (i + 1) % 4;
            Line(corner[i].x, corner[i].y, corner[next].x, corner[next].y);
        }
        return;
    }
    if (rect_mode_ == kRectCenter) {
        auto center_x = x + width / 2;
        auto center_y = y + height / 2;
        for (int i = 0; i < 4; i++) {
            auto next = (i + 1) % 4;
            Line(corner[i].x - center_x, corner[i].y - center_y, corner[next].x - center_x, corner[next].y - center_y);
        }
        return;
    }
    cerr << "ERROR: Invalid rectangle mode: " << rect_mode_ << endl;
}

void P5SDL::Line(float x1, float y1, float x2, float y2)
{
    Line((int)x1, (int)y1, (int)x2, (int)y2);
}

void P5SDL::Line(int x1, int y1, int x2, int y2)
{
    // Rotate
    double sin_value = sin(rotation_radians_);
    double cos_value = cos(rotation_radians_);

    double rotated_x1 = x1 * cos_value - y1 * sin_value;
    double rotated_y1 = x1 * sin_value + y1 * cos_value;
    double rotated_x2 = x2 * cos_value - y2 * sin_value;
    double rotated_y2 = x2 * sin_value + y2 * cos_value;

    // Translate
    int final_x1 = static_cast<int>(rotated_x1 + origin_x_);
    int final_y1 = static_cast<int>(rotated_y1 + origin_y_);
    int final_x2 = static_cast<int>(rotated_x2 + origin_x_);
    int final_y2 = static_cast<int>(rotated_y2 + origin_y_);

    // Draw using stroke weight
    auto dx = abs(final_x1 - final_x2);
    auto dy = abs(final_y1 - final_y2);
    SDL_SetRenderDrawColor(renderer_, stroke_color_.r, stroke_color_.g, stroke_color_.b, stroke_color_.a);
    for (int i = -stroke_weight_ / 2; i <= stroke_weight_ / 2; i++) {
        auto swx = i * (dx < dy);
        auto swy = i * (dx >= dy);
        SDL_RenderDrawLine(renderer_, final_x1 + swx, final_y1 + swy, final_x2 + swx, final_y2 + swy);
    }
}

void P5SDL::Lines(SDL_Point points[], int count)
{
    for (int i = 1; i < count; i++) {
        Line(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);
    }
}

void P5SDL::HandleEvents()
{
    mouse_button_clicked_[kMouseLeftButton] = false;
    mouse_button_clicked_[kMouseMiddleButton] = false;
    mouse_button_clicked_[kMouseRightButton] = false;

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
        {
            if (event.button.button == SDL_BUTTON_LEFT)
                mouse_button_held_[kMouseLeftButton] = true;
            if (event.button.button == SDL_BUTTON_MIDDLE)
                mouse_button_held_[kMouseMiddleButton] = true;
            if (event.button.button == SDL_BUTTON_RIGHT)
                mouse_button_held_[kMouseRightButton] = true;
            auto current_time = SDL_GetTicks();
            if (current_time - last_mouse_click_time > mouse_debounce_milliseconds_) {
                if (event.button.button == SDL_BUTTON_LEFT)
                    mouse_button_clicked_[kMouseLeftButton] = true;
                if (event.button.button == SDL_BUTTON_MIDDLE)
                    mouse_button_clicked_[kMouseMiddleButton] = true;
                if (event.button.button == SDL_BUTTON_RIGHT)
                    mouse_button_clicked_[kMouseRightButton] = true;
                last_mouse_click_time = current_time;
            }
            break;
        }
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
                mouse_button_held_[kMouseLeftButton] = false;
            if (event.button.button == SDL_BUTTON_MIDDLE)
                mouse_button_held_[kMouseMiddleButton] = false;
            if (event.button.button == SDL_BUTTON_RIGHT)
                mouse_button_held_[kMouseRightButton] = false;
            break;
        default:
            break;
        }
    }
}

bool P5SDL::IsKeyPressed(Sint32 key)
{
    return std::find(pressed_keys_.begin(), pressed_keys_.end(), key) != pressed_keys_.end();
}

void P5SDL::Background(Uint8 gray_scale)
{
    Background({ gray_scale, gray_scale, gray_scale, 255 });
}

void P5SDL::Background(SDL_Color background_color)
{
    background_color_ = background_color;
    SDL_SetRenderDrawColor(Renderer(), background_color_.r, background_color_.g, background_color_.b, background_color_.a);
    SDL_RenderClear(Renderer());
}

//END

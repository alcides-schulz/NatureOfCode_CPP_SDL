#include "P5SDL.h"

using namespace std;

bool P5SDL::Init()
{
    int result = SDL_Init(SDL_INIT_EVERYTHING);
    if (result != 0) {
        std::cerr << "SDL_Init failed, result: " << result << ".\n";
        std::getchar();
        return false;
    }
    if (TTF_Init() < 0) {
        std::cerr << "SDL_ttf could not initialize! TTF_Error: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    _text_font = TTF_OpenFont("./Common/cour.ttf", 16);
    if (_text_font == nullptr) {
        std::cerr << "Failed to load font! TTF_Error: " << TTF_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    if (_window_x == -1 || _window_y == -1) {
        SDL_DisplayMode display_mode;
        SDL_GetCurrentDisplayMode(0, &display_mode);
        if (_window_x == -1)
            _window_x = (display_mode.w - _window_width) / 2;
        if (_window_y == -1)
            _window_y = (display_mode.h - _window_height) / 2;
    }
    _window = SDL_CreateWindow(_window_title, _window_x, _window_y, _window_width, _window_height, _window_flags);
    if (_window == 0) {
        std::cout << "SDL_CreateWindow failed.\n";
        std::getchar();
        return false;
    }
    SDL_GetWindowSize(_window, &_window_width, &_window_height);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if (_renderer == 0) {
        std::cout << "SDL_CreateRenderer failed.\n";
        std::getchar();
        return false;
    }
    SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
    for (int degree = 0; degree < 360; degree++) {
        _circle_cos_cache[degree] = cos(degree * M_PI / 180.0);
        _circle_sin_cache[degree] = sin(degree * M_PI / 180.0);
    }
    _is_running = Setup();
    if (!_is_running) {
        SDL_DestroyWindow(_window);
        SDL_DestroyRenderer(_renderer);
        TTF_CloseFont(_text_font);
        TTF_Quit();
        SDL_Quit();
    }
    return _is_running;
}

void P5SDL::Run()
{
    Uint32 start_time = SDL_GetTicks();
    Uint32 timer = start_time;
    int local_frame_count = 0;
    _loop = true;

    while (_is_running) {
        Uint32 frame_start = SDL_GetTicks();
        Uint32 elapsed_time = frame_start - start_time;
        start_time = frame_start;

        HandleEvents();
        if (_loop) {
            if (!Draw()) {
                _is_running = false;
            }
        }
        SDL_RenderPresent(Renderer());
        ResetMatrix();

        local_frame_count++;
        _global_frame_count++;
        if (SDL_GetTicks() - timer > 1000) {
            std::string t = _window_title;
            t.append(" (");
            t.append(std::to_string(local_frame_count));
            t.append(" FPS)");
            SDL_SetWindowTitle(_window, t.c_str());
            timer += 1000;
            local_frame_count = 0;
        }

        Uint32 frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < _MaxFrameTime) {
            SDL_Delay((int)(_MaxFrameTime - frame_time));
        }
    }

    Cleanup();

    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    TTF_CloseFont(_text_font);
    TTF_Quit();
    SDL_Quit();
}

void P5SDL::Translate(int x, int y) 
{ 
    double sin_value = sin(_rotation_radians);
    double cos_value = cos(_rotation_radians);
    double rotated_x = x * cos_value - y * sin_value;
    double rotated_y = x * sin_value + y * cos_value;
    _origin_x += (int)rotated_x;
    _origin_y += (int)rotated_y;
}

void P5SDL::Translate(float x, float y)
{ 
    Translate((int)x, (int)y);
}

void P5SDL::Circle(float center_x, float center_y, int diameter)
{
    Circle((int)center_x, (int)center_y, diameter);
}

void P5SDL::Circle(int center_x, int center_y, int diameter)
{
    // Translate and rotate circle position
    double sin_value = sin(_rotation_radians);
    double cos_value = cos(_rotation_radians);
    double rotated_x = center_x * cos_value - center_y * sin_value;
    double rotated_y = center_x * sin_value + center_y * cos_value;
    auto final_x = (int)(rotated_x + _origin_x);
    auto final_y = (int)(rotated_y + _origin_y);
    // Fill in
    if (_fill_color.r != _background_color.r || _fill_color.g != _background_color.g || _fill_color.b != _background_color.b || _fill_color.a != _background_color.a) {
        auto radius = diameter / 2;
        auto radius2 = radius * radius;
        SDL_SetRenderDrawColor(_renderer, _fill_color.r, _fill_color.g, _fill_color.b, _fill_color.a);
        for (int y = -radius; y <= radius; y++) {
            int maxX = (int)(sqrt(radius2 - y * y));
            SDL_RenderDrawLine(_renderer, final_x - maxX, final_y + y, final_x + maxX, final_y + y);
        }
    }
    // Draw circle
    SDL_SetRenderDrawColor(_renderer, _stroke_color.r, _stroke_color.g, _stroke_color.b, _stroke_color.a);
    for (int thickness = 0; thickness < _stroke_weight; thickness++) {
        auto radius = diameter / 2 - thickness;
        for (int degree = 0; degree < 360; degree++) {
            auto x = final_x + radius * _circle_cos_cache[degree]; //cos(degree * M_PI / 180)
            auto y = final_y + radius * _circle_sin_cache[degree]; //sin(degree * M_PI / 180)
            SDL_RenderDrawPoint(_renderer, (int)x, (int)y);
        }
    }
}

void P5SDL::Square(int x, int y, int width)
{
    Rect(x, y, width, width);
}

void P5SDL::Rect(int x, int y, int width, int height)
{
    if (_rect_mode == kRectCorner) {
        // Fill in
        if (_fill_color.r != _background_color.r || _fill_color.g != _background_color.g || _fill_color.b != _background_color.b || _fill_color.a != _background_color.a) {
            auto saved_stroke_color = _stroke_color;
            auto saved_stroke_weight = _stroke_weight;
            Stroke(_fill_color);
            StrokeWeight(2);
            for (int i = y + 1; i < y + height - 1; i++) {
                Line(x, i, x + width - 1, i);
            }
            Stroke(saved_stroke_color);
            StrokeWeight(saved_stroke_weight);
        }
        Line(x, y, x + width, y);
        Line(x + width, y, x + width, y + height);
        Line(x + width, y + height, x, y + height);
        Line(x, y + height, x, y);
        return;
    }
    if (_rect_mode == kRectCenter) {
        auto middle_x = width / 2;
        auto middle_y = height / 2;
        // Fill in
        if (_fill_color.r != _background_color.r || _fill_color.g != _background_color.g || _fill_color.b != _background_color.b || _fill_color.a != _background_color.a) {
            auto saved_stroke_color = _stroke_color;
            auto saved_stroke_weight = _stroke_weight;
            Stroke(_fill_color);
            StrokeWeight(2);
            for (int i = y - middle_y; i < y + middle_y; i++) {
                Line(x - middle_x, i, x + middle_x, i);
            }
            Stroke(saved_stroke_color);
            StrokeWeight(saved_stroke_weight);
        }
        // Rectangle Lines
        Line(x - middle_x, y - middle_y, x + middle_x, y - middle_y);
        Line(x + middle_x, y - middle_y, x + middle_x, y + middle_y);
        Line(x + middle_x, y + middle_y, x - middle_x, y + middle_y);
        Line(x - middle_x, y + middle_y, x - middle_x, y - middle_y);
        return;
    }
    cerr << "ERROR: Invalid rectangle mode: " << _rect_mode << endl;
}

void P5SDL::Line(float x1, float y1, float x2, float y2)
{
    Line((int)x1, (int)y1, (int)x2, (int)y2);
}

void P5SDL::Line(int x1, int y1, int x2, int y2)
{
    // Rotate
    double sin_value = sin(_rotation_radians);
    double cos_value = cos(_rotation_radians);

    double rotated_x1 = x1 * cos_value - y1 * sin_value;
    double rotated_y1 = x1 * sin_value + y1 * cos_value;
    double rotated_x2 = x2 * cos_value - y2 * sin_value;
    double rotated_y2 = x2 * sin_value + y2 * cos_value;

    // Translate
    int final_x1 = static_cast<int>(rotated_x1 + _origin_x);
    int final_y1 = static_cast<int>(rotated_y1 + _origin_y);
    int final_x2 = static_cast<int>(rotated_x2 + _origin_x);
    int final_y2 = static_cast<int>(rotated_y2 + _origin_y);

    // Draw using stroke weight
    auto dx = abs(final_x1 - final_x2);
    auto dy = abs(final_y1 - final_y2);
    SDL_SetRenderDrawColor(_renderer, _stroke_color.r, _stroke_color.g, _stroke_color.b, _stroke_color.a);
    for (int i = -_stroke_weight / 2; i <= _stroke_weight / 2; i++) {
        auto swx = i * (dx < dy);
        auto swy = i * (dx >= dy);
        SDL_RenderDrawLine(_renderer, final_x1 + swx, final_y1 + swy, final_x2 + swx, final_y2 + swy);
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
    _mouse_button_clicked[kMouseLeftButton] = false;
    _mouse_button_clicked[kMouseMiddleButton] = false;
    _mouse_button_clicked[kMouseRightButton] = false;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            {
                auto found = std::find(_pressed_keys.begin(), _pressed_keys.end(), event.key.keysym.sym);
                if (found == _pressed_keys.end()) {
                    _pressed_keys.push_back(event.key.keysym.sym);
                }
            }
            break;
        case SDL_KEYUP:
            _pressed_keys.remove(event.key.keysym.sym);
            break;
        case SDL_QUIT:
            _is_running = false;
            break;
        case SDL_MOUSEMOTION:
            _mouse_position.x = event.motion.x;
            _mouse_position.y = event.motion.y;
            break;
        case SDL_MOUSEBUTTONDOWN:
        {
            if (event.button.button == SDL_BUTTON_LEFT)
                _mouse_button_held[kMouseLeftButton] = true;
            if (event.button.button == SDL_BUTTON_MIDDLE)
                _mouse_button_held[kMouseMiddleButton] = true;
            if (event.button.button == SDL_BUTTON_RIGHT)
                _mouse_button_held[kMouseRightButton] = true;
            auto current_time = SDL_GetTicks();
            if (current_time - _last_mouse_click_time > _mouse_debounce_milliseconds) {
                if (event.button.button == SDL_BUTTON_LEFT)
                    _mouse_button_clicked[kMouseLeftButton] = true;
                if (event.button.button == SDL_BUTTON_MIDDLE)
                    _mouse_button_clicked[kMouseMiddleButton] = true;
                if (event.button.button == SDL_BUTTON_RIGHT)
                    _mouse_button_clicked[kMouseRightButton] = true;
                _last_mouse_click_time = current_time;
            }
            break;
        }
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
                _mouse_button_held[kMouseLeftButton] = false;
            if (event.button.button == SDL_BUTTON_MIDDLE)
                _mouse_button_held[kMouseMiddleButton] = false;
            if (event.button.button == SDL_BUTTON_RIGHT)
                _mouse_button_held[kMouseRightButton] = false;
            break;
        default:
            break;
        }
    }
}

bool P5SDL::IsKeyPressed(Sint32 key)
{
    return std::find(_pressed_keys.begin(), _pressed_keys.end(), key) != _pressed_keys.end();
}

void P5SDL::Background(Uint8 gray_scale)
{
    Background({ gray_scale, gray_scale, gray_scale, 255 });
}

void P5SDL::Background(SDL_Color background_color)
{
    _background_color = background_color;
    SDL_SetRenderDrawColor(Renderer(), _background_color.r, _background_color.g, _background_color.b, _background_color.a);
    SDL_RenderClear(Renderer());
}

void P5SDL::Push(void)
{
    MATRIX current;
    current.rotation_radians = _rotation_radians;
    current.origin_x = _origin_x;
    current.origin_y = _origin_y;
    _matrix_stack.push(current);
}

void P5SDL::Pop(void)
{
    if (!_matrix_stack.empty()) {
        auto restore = _matrix_stack.top();
        _matrix_stack.pop();
        _rotation_radians = restore.rotation_radians;
        _origin_x = restore.origin_x;
        _origin_y = restore.origin_y;
    }
}

void P5SDL::TextSize(int size)
{
    if (_text_font != nullptr)
        TTF_CloseFont(_text_font);
    _text_font = TTF_OpenFont("./Common/cour.ttf", size);
    if (_text_font == nullptr) {
        std::cerr << "Failed to load font size: " << size << " TTF_Error: " << TTF_GetError() << std::endl;
    }
}

void P5SDL::Text(string text, int x, int y)
{
    SDL_Surface* text_surface = TTF_RenderText_Solid(_text_font, text.c_str(), _stroke_color);
    if (text_surface == nullptr) {
        std::cerr << "Text function error for text '" << text << "'" << std::endl;
        std::cerr << "Failed to create text surface! TTF_Error: " << TTF_GetError() << std::endl;
        return;
    }
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(_renderer, text_surface);
    SDL_FreeSurface(text_surface);
    if (text_texture == nullptr) {
        std::cerr << "Failed to create text texture! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_Rect text_rectangle;
    SDL_QueryTexture(text_texture, nullptr, nullptr, &text_rectangle.w, &text_rectangle.h);
    text_rectangle.x = x;
    text_rectangle.y = y;

    SDL_SetRenderDrawColor(_renderer, _background_color.r, _background_color.g, _background_color.b, _background_color.a);
    SDL_RenderCopy(_renderer, text_texture, nullptr, &text_rectangle);
    
    SDL_DestroyTexture(text_texture);
}

//END

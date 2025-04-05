#ifndef P5SDL_H
#define P5SDL_H

#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <string>
#include <cmath>
#include <random>
#include <cstdlib>
#include <list>
#include <ctime>
#include <chrono>

using namespace std;

constexpr int kMouseLeftButton = 0;
constexpr int kMouseMiddleButton = 1;
constexpr int kMouseRightButton = 2;

constexpr SDL_Color kColorWhite = { 255, 255, 255, 255 };
constexpr SDL_Color kColorBlack = { 0, 0, 0, 255 };
constexpr SDL_Color kColorRed = { 255, 0, 0, 255 };
constexpr SDL_Color kColorGreen = { 0, 255, 0, 255 };
constexpr SDL_Color kColorBlue = { 0, 0, 255, 255 };
constexpr SDL_Color kColorGray = { 128, 128, 128, 255 };
constexpr SDL_Color kColorLightGray = { 211, 211, 211, 255 };

constexpr int kRectCorner = 0;
constexpr int kRectCenter = 1;

typedef struct s_matrix {
    double  rotation_radians;
    int     origin_x;
    int     origin_y;
}   MATRIX;

class P5SDL
{
public:
    P5SDL() { };
    P5SDL(const char *title, int x, int y, int width, int height, int flags) :
        _window_title(title), _window_x(x), _window_y(y), _window_width(width), _window_height(height), _window_flags(flags) { };
    virtual bool Setup(void) { return true; };
    virtual bool Draw(void) { return true; };
    virtual void Cleanup(void) {};
    const char *WindowTitle(void) { return _window_title; }
    int Width(void) { return _window_width; }
    int Height(void) { return _window_height; }
    SDL_Renderer* Renderer(void) { return _renderer; }
    SDL_Window* Window(void) { return _window; }
    SDL_Point MousePosition(void) { return _mouse_position; }
    bool IsMouseButtonHeld(int mouse_button) { return _mouse_button_held[mouse_button]; }
    bool IsMouseButtonClicked(int mouse_button) { return _mouse_button_clicked[mouse_button]; }
    Uint32 FrameCount(void) { return _global_frame_count; }
    bool Init(void);
    void Run(void);
    bool IsKeyPressed(Sint32 key);

    void Background(Uint8 gray_scale);
    void Background(SDL_Color background_color);
    void Translate(int x, int y);
    void Translate(float x, float y);
    void Rotate(double radians) { _rotation_radians += radians; }
    void ResetMatrix(void) { _origin_x = _origin_y = 0, _rotation_radians = 0; }
    void StrokeWeight(int stroke_weight) { _stroke_weight = stroke_weight; }
    void Stroke(Uint8 gray_value) { _stroke_color = SDL_Color{ gray_value, gray_value, gray_value, 255 }; };
    void Stroke(SDL_Color color) { _stroke_color = color; };
    void Stroke(Uint8 gray_value, Uint8 alpha) { _stroke_color = SDL_Color{ gray_value, gray_value, gray_value, alpha }; };
    void Fill(Uint8 gray_value) { _fill_color = SDL_Color{ gray_value, gray_value, gray_value, 255 }; };
    void Fill(Uint8 gray_value, Uint8 alpha) { _fill_color = SDL_Color{ gray_value, gray_value, gray_value, alpha }; };
    void Fill(SDL_Color color) { _fill_color = color; };
    void Circle(int center_x, int center_y, int diameter);
    void Circle(float center_x, float center_y, int diameter);
    void Line(int x1, int y1, int x2, int y2);
    void Line(float x1, float y1, float x2, float y2);
    void Lines(SDL_Point points[], int count);
    void Rect(int x, int y, int width, int heigth);
    void RectMode(int mode) { _rect_mode = mode; };
    void Square(int x, int y, int width);
    void NoLoop(void) { _loop = false; };
    void Loop(void) { _loop = true; };
    void Push(void);
    void Pop(void);
private:
    SDL_Window      *_window;
    const char      *_window_title;
    int             _window_x = 0;
    int             _window_y = 0;
    int             _window_width = 0;
    int             _window_height = 0;
    int             _window_flags = 0;
    SDL_Renderer    *_renderer;
    int             _origin_x = 0;
    int             _origin_y = 0;
    double          _rotation_radians = 0;
    int             _stroke_weight = 1;
    SDL_Color       _stroke_color = kColorBlack;
    SDL_Color       _fill_color = kColorWhite;
    SDL_Color       _background_color = kColorWhite;
    int             _rect_mode = kRectCorner;
    list<Sint32>    _pressed_keys;
    bool            _mouse_button_held[3] = { false, false, false };
    bool            _mouse_button_clicked[3] = { false, false, false };
    SDL_Point       _mouse_position = { 0, 0 };
    bool            _is_running = false;
    const int       kFPS = 60;
    const Uint32    kMaxFrameTime = (Uint32)(1000.0f / kFPS);
    Uint32          _global_frame_count;
    bool            _loop = true;
    Uint32          _last_mouse_click_time = SDL_GetTicks();
    Uint32          _mouse_debounce_milliseconds = 200;
    double          _circle_cos_cache[360];
    double          _circle_sin_cache[360];
    stack<MATRIX>   _matrix_stack;

    void            HandleEvents();
};

#endif

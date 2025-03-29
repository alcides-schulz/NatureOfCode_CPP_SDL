#ifndef P5SDL_H
#define P5SDL_H

#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include <vector>
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

class P5SDL
{
public:
    P5SDL() { };
    P5SDL(const char *title, int x, int y, int width, int height, int flags) :
        window_title_(title), window_x_(x), window_y_(y), window_width_(width), window_height_(height), window_flags_(flags) { };
    virtual bool Setup(void) { return true; };
    virtual bool Draw(void) { return true; };
    virtual void Cleanup(void) {};
    const char *WindowTitle(void) { return window_title_; }
    int Width(void) { return window_width_; }
    int Height(void) { return window_height_; }
    SDL_Renderer* Renderer(void) { return renderer_; }
    SDL_Window* Window(void) { return window_; }
    SDL_Point MousePosition(void) { return mouse_position_; }
    bool IsMouseButtonHeld(int mouse_button) { return mouse_button_held_[mouse_button]; }
    bool IsMouseButtonClicked(int mouse_button) { return mouse_button_clicked_[mouse_button]; }
    Uint32 FrameCount(void) { return global_frame_count_; }
    bool Init(void);
    void Run(void);
    bool IsKeyPressed(Sint32 key);

    void Background(Uint8 gray_scale);
    void Background(SDL_Color background_color);
    void Translate(int x, int y) { origin_x_ += x, origin_y_ += y; }
    void Translate(float x, float y) { origin_x_ += (int)x, origin_y_ += (int)y; }
    void Rotate(double radians) { rotation_radians_ += radians; }
    void ResetMatrix(void) { origin_x_ = origin_y_ = 0, rotation_radians_ = 0; }
    void StrokeWeight(int stroke_weight) { stroke_weight_ = stroke_weight; }
    void Stroke(Uint8 gray_value) { stroke_color_ = SDL_Color{ gray_value, gray_value, gray_value, 255 }; };
    void Stroke(SDL_Color color) { stroke_color_ = color; };
    void Fill(Uint8 gray_value) { fill_color_ = SDL_Color{ gray_value, gray_value, gray_value, 255 }; };
    void Fill(Uint8 gray_value, Uint8 alpha) { fill_color_ = SDL_Color{ gray_value, gray_value, gray_value, alpha }; };
    void Fill(SDL_Color color) { fill_color_ = color; };
    void Circle(int center_x, int center_y, int diameter);
    void Circle(float center_x, float center_y, int diameter);
    void Line(int x1, int y1, int x2, int y2);
    void Line(float x1, float y1, float x2, float y2);
    void Lines(SDL_Point points[], int count);
    void Rect(int x, int y, int width, int heigth);
    void RectMode(int mode) { rect_mode_ = mode; };
private:
    SDL_Window      *window_;
    const char      *window_title_;
    int             window_x_ = 0;
    int             window_y_ = 0;
    int             window_width_ = 0;
    int             window_height_ = 0;
    int             window_flags_ = 0;
    SDL_Renderer    *renderer_;
    int             origin_x_ = 0;
    int             origin_y_ = 0;
    double          rotation_radians_ = 0;
    int             stroke_weight_ = 2;
    SDL_Color       stroke_color_ = kColorBlack;
    SDL_Color       fill_color_ = kColorWhite;
    SDL_Color       background_color_ = kColorWhite;
    int             rect_mode_ = kRectCorner;
    list<Sint32>    pressed_keys_;
    bool            mouse_button_held_[3] = { false, false, false };
    bool            mouse_button_clicked_[3] = { false, false, false };
    SDL_Point       mouse_position_ = { 0, 0 };
    bool            is_running_ = false;
    const int       kFPS = 60;
    const Uint32    kMaxFrameTime = (Uint32)(1000.0f / kFPS);
    Uint32          global_frame_count_;
    Uint32          last_mouse_click_time = SDL_GetTicks();
    Uint32          mouse_debounce_milliseconds_ = 200;
    double          circle_cos_cache[360];
    double          circle_sin_cache[360];

    void            HandleEvents();
};

#endif

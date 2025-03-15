#ifndef SDL_FRAMEWORK_H
#define SDL_FRAMEWORK_H

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

class SDL_Framework
{
public:
    SDL_Framework() { };
    SDL_Framework(const char *title, int x, int y, int width, int height, int flags) :
        window_title_(title), window_x_(x), window_y_(y), window_width_(width), window_height_(height), window_flags_(flags) { };
    virtual bool Setup(void) { return true; };
    virtual bool Draw(void) { return true; };
    virtual void UserClean(void) {};
    const char *WindowTitle(void) { return window_title_; }
    int Width(void) { return window_width_; }
    int Height(void) { return window_height_; }
    SDL_Renderer* Renderer(void) { return renderer_; }
    SDL_Window* Window(void) { return window_; }
    void ClearScreen(void);
    SDL_Point MousePosition(void) { return mouse_position_; }
    bool IsMouseButtonPressed(int mouse_button) { return mouse_button_states_[mouse_button]; }
    Uint32 FrameCount(void) { return global_frame_count_; }
    bool Init(void);
    void Run(void);
    bool IsKeyPressed(Sint32 key);
    void Translate(int x, int y) { origin_x_ += x, origin_y_ += y; }
    void RotateRadians(double radians) { rotation_radians_ += radians; }
    void RotateDegrees(double degrees) { rotation_radians_ += degrees * M_PI / 180.0; }
    void ResetMatrix(void) { origin_x_ = origin_y_ = 0, rotation_radians_ = 0; }
    void DrawCircle(int center_x, int center_y, int diameter, SDL_Color color, bool fill);
    void DrawCircle(float center_x, float center_y, int diameter, SDL_Color color, bool fill);
    void DrawLine(int x1, int y1, int x2, int y2, SDL_Color color);
    void DrawLine(float x1, float y1, float x2, float y2, SDL_Color color);
    void DrawRectangle(int x, int y, int width, int heigth, SDL_Color color);
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
    list<Sint32>    pressed_keys_;
    bool            mouse_button_states_[3] = { false, false, false };
    SDL_Point       mouse_position_ = { 0, 0 };
    bool            is_running_ = false;
    const int       kFPS = 60;
    const Uint32    kMaxFrameTime = (Uint32)(1000.0f / kFPS);
    Uint32          global_frame_count_;
    void            HandleEvents();
};

#endif

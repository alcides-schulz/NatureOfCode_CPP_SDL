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
#include <time.h>

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
    virtual bool UserInit() { return true; };
    virtual bool UserRender(int elapsed_time) { return true; };
    virtual void UserClean() {};
    const char *WindowTitle() { return window_title_; }
    int WindowWidth() { return window_width_; }
    int WindowHeight() { return window_height_; }
    SDL_Renderer* Renderer() { return renderer_; }
    SDL_Window* Window() { return window_; }
    SDL_Point MousePosition() { return mouse_position_; }
    bool IsMouseButtonPressed(int mouse_button) { return mouse_button_states_[mouse_button]; }
    bool Init();
    void Run();
    void DrawCircle(SDL_Point center, int radius, SDL_Color color, bool fill);
    bool IsKeyPressed(Sint32 key);
private:
    SDL_Window      *window_;
    const char      *window_title_;
    int             window_x_ = 0;
    int             window_y_ = 0;
    int             window_width_ = 0;
    int             window_height_ = 0;
    int             window_flags_ = 0;
    SDL_Renderer    *renderer_;
    list<Sint32>    pressed_keys_;
    bool            mouse_button_states_[3] = { false, false, false };
    SDL_Point       mouse_position_ = { 0, 0 };
    bool            is_running_ = false;
    const int       kFPS = 60;
    const Uint32    kMaxFrameTime = (Uint32)(1000.0f / kFPS);
    void            HandleEvents();
};

#endif

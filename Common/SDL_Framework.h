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

using namespace std;

constexpr int kMouseLeftButton = 0;
constexpr int kMouseMiddleButton = 1;
constexpr int kMouseRightButton = 2;

class Vector2D
{
public:
    float x;
    float y;
    Vector2D() : x(0), y(0) {}
    Vector2D(float x, float y) : x(x), y(y) {}
    Vector2D(double x, double y) : x((float)x), y((float)y) {}
    Vector2D(int x, int y) : x((float)x), y((float)y) {}
    int IntX() { return (int)x; }
    int IntY() { return (int)y; }

    void Add(Vector2D v2)
    {
        x += v2.x;
        y += v2.y;
    }

    void Subtract(Vector2D v2)
    {
        x -= v2.x;
        y -= v2.y;
    }

    void Multiply(float value)
    {
        x *= value;
        y *= value;
    }

    void Divide(float value)
    {
        x /= value;
        y /= value;
    }

    float Magnitude()
    {
        return sqrtf(x * x + y * y);
    }

    void Normalize()
    {
        float magnitude = Magnitude();
        if (magnitude != 0) {
            Divide(magnitude);
        }
    }

    void SetMag(float magnitude)
    {
        Normalize();
        Multiply(magnitude);
    }
 
    void Limit(float max)
    {
        if (Magnitude() > max * max) {
            Normalize();
            Multiply(max);
        }
    }
};

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
    bool Init(const char* title, int x, int y, int width, int height, int flags);
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

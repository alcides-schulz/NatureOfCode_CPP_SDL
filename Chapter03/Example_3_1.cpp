#include "Example_3_1.h"

bool Example_3_1::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
    SDL_RenderClear(Renderer());

    // Translate() function simulation
    int screen_x_center = WindowWidth() / 2;
    int screen_y_center = WindowHeight() / 2;
    int line_x1 = screen_x_center - 100, line_y1 = screen_y_center - 100;
    int line_x2 = screen_x_center + 100, line_y2 = screen_y_center + 100;

    // Rotate() function simulation
    int centerX = (line_x1 + line_x2) / 2;
    int centerY = (line_y1 + line_y2) / 2;
    double radians = angle_ * M_PI / 180.0;
    int rotatedX1 = (int)(centerX + (line_x1 - centerX) * std::cos(radians) - (line_y1 - centerY) * std::sin(radians));
    int rotatedY1 = (int)(centerY + (line_x1 - centerX) * std::sin(radians) + (line_y1 - centerY) * std::cos(radians));
    int rotatedX2 = (int)(centerX + (line_x2 - centerX) * std::cos(radians) - (line_y2 - centerY) * std::sin(radians));
    int rotatedY2 = (int)(centerY + (line_x2 - centerX) * std::sin(radians) + (line_y2 - centerY) * std::cos(radians));

    SDL_SetRenderDrawColor(Renderer(), 255, 0, 0, 255); // Red line
    SDL_RenderDrawLine(Renderer(), rotatedX1, rotatedY1, rotatedX2, rotatedY2);

    DrawCircle({ rotatedX1, rotatedY1 }, 5, { 255, 0, 0, 0 }, true);
    DrawCircle({ rotatedX2, rotatedY2 }, 5, { 255, 0, 0, 0 }, true);

    angleVelocity_ += angleAcceleration_;
    angle_ += angleVelocity_;

    return true;
}

// END

#include "Example_3_1.h"

bool Example_3_1::UserRender(int elapsed_time)
{
    ClearScreen();

    // Translate() function simulation
    int screen_x_center = WindowWidth() / 2;
    int screen_y_center = WindowHeight() / 2;
    int line_x1 = screen_x_center - 100;
    int line_y1 = screen_y_center - 100;
    int line_x2 = screen_x_center + 100;
    int line_y2 = screen_y_center + 100;

    // Rotate() function simulation
    int line_center_x = (line_x1 + line_x2) / 2;
    int line_center_y = (line_y1 + line_y2) / 2;
    double radians = angle_ * M_PI / 180.0;
    int rotated_x1 = (int)(line_center_x + (line_x1 - line_center_x) * std::cos(radians) - (line_y1 - line_center_y) * std::sin(radians));
    int rotated_y1 = (int)(line_center_y + (line_x1 - line_center_x) * std::sin(radians) + (line_y1 - line_center_y) * std::cos(radians));
    int rotated_x2 = (int)(line_center_x + (line_x2 - line_center_x) * std::cos(radians) - (line_y2 - line_center_y) * std::sin(radians));
    int rotated_y2 = (int)(line_center_y + (line_x2 - line_center_x) * std::sin(radians) + (line_y2 - line_center_y) * std::cos(radians));

    SDL_SetRenderDrawColor(Renderer(), 255, 0, 0, 255); // Red line
    SDL_RenderDrawLine(Renderer(), rotated_x1, rotated_y1, rotated_x2, rotated_y2);

    DrawCircle({ rotated_x1, rotated_y1 }, 5, { 255, 0, 0, 0 }, true);
    DrawCircle({ rotated_x2, rotated_y2 }, 5, { 255, 0, 0, 0 }, true);

    angleVelocity_ += angleAcceleration_;
    angle_ += angleVelocity_;

    return true;
}

// END

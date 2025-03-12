#include "Example_3_1.h"

bool Example_3_1::UserInit(void)
{
    angle_ = 0;
    angleVelocity_ = 0;
    angleAcceleration_ = 0.001f;

    return true;
}

bool Example_3_1::UserRender(int elapsed_time)
{
    ClearScreen();

    Translate(WindowWidth() / 2, WindowHeight() / 2);

    int line_x1 = -60;
    int line_y1 = 0;
    int line_x2 = 60;
    int line_y2 = 0;

    // Rotate() function simulation
    int line_center_x = (line_x1 + line_x2) / 2;
    int line_center_y = (line_y1 + line_y2) / 2;
    float radians = angle_ * (float)M_PI / 180.0f;
    float cos = std::cos(radians);
    float sin = std::sin(radians);
    int rotated_x1 = (int)(line_center_x + (line_x1 - line_center_x) * cos - (line_y1 - line_center_y) * sin);
    int rotated_y1 = (int)(line_center_y + (line_x1 - line_center_x) * sin + (line_y1 - line_center_y) * cos);
    int rotated_x2 = (int)(line_center_x + (line_x2 - line_center_x) * cos - (line_y2 - line_center_y) * sin);
    int rotated_y2 = (int)(line_center_y + (line_x2 - line_center_x) * sin + (line_y2 - line_center_y) * cos);

    SDL_RenderDrawLine(Renderer(), rotated_x1, rotated_y1, rotated_x2, rotated_y2);
    DrawLine(rotated_x1, rotated_y1, rotated_x2, rotated_y2, kColorBlack);

    DrawCircle({ rotated_x1, rotated_y1 }, 16, kColorBlack, true);
    DrawCircle({ rotated_x2, rotated_y2 }, 16, kColorBlack, true);

    angleVelocity_ += angleAcceleration_;
    angle_ += angleVelocity_;

    return true;
}

// END

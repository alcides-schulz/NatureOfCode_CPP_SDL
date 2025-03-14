#include "Example_3_1.h"

bool Example_3_1::UserInit(void)
{
    angle_ = 0;
    angleVelocity_ = 0;
    angleAcceleration_ = 0.0001f;

    return true;
}

bool Example_3_1::UserRender(int elapsed_time)
{
    ClearScreen();

    int line_x1 = -60;
    int line_y1 = 0;
    int line_x2 = 60;
    int line_y2 = 0;

    Translate(WindowWidth() / 2, WindowHeight() / 2);
    RotateRadians(angle_);
    DrawLine(line_x1, line_y1, line_x2, line_y2, kColorBlack);
    DrawCircle({ line_x1, line_y1 }, 16, kColorGray, true);
    DrawCircle({ line_x2, line_y2 }, 16, kColorGray, true);

    angleVelocity_ += angleAcceleration_;
    angle_ += angleVelocity_;

    return true;
}

// END

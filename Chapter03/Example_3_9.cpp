#include "Example_3_9.h"
#include "../Common/P5Functions.h"

bool Example_3_9::UserInit(void)
{
    start_angle_ = 0;
    angle_velocity_ = 0.2f;

    return true;
}

bool Example_3_9::UserRender(int elapsed_time)
{
    ClearScreen();
    /*
      let angle = startAngle;
  startAngle += 0.02;

  for (let x = 0; x <= width; x += 24) {
    let y = map(sin(angle), -1, 1, 0, height);
    stroke(0);
    strokeWeight(2);
    fill(127, 127);
    circle(x, y, 48);
    angle += angleVelocity;
  }
    */

    auto angle = start_angle_;
    start_angle_ += 0.02f;

    for (int x = 0; x <= WindowWidth(); x += 24) {
        auto y = static_cast<int>(P5Functions::Map(sin(angle), -1, 1, 0, WindowHeight()));
        DrawCircle(x, y, 48, kColorGray, true);
        DrawCircle(x, y, 48, kColorBlack, false);
        angle += angle_velocity_;
    }

    return true;
}

// END

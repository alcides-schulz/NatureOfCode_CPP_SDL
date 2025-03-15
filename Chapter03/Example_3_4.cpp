#include "Example_3_4.h"

bool Example_3_4::Setup(void)
{
    radius = Height() * 0.45f;
    theta = 0;

    return true;
}

bool Example_3_4::Draw()
{
    ClearScreen();
  
    Translate(Width() / 2, Height() / 2);
    
    auto x = static_cast<int>(radius * std::cos(theta));
    auto y = static_cast<int>(radius * std::sin(theta));

    DrawLine(0, 0, x, y, kColorBlack);
    DrawCircle(x, y, 30, kColorBlack, true);

    theta += 0.02f;

    return true;
}

// END

#include "CircleTest.h"

bool CircleTest::Draw()
{
    ClearScreen();

    DrawCircle(0, 0, 100, kColorGray, true);
    Translate(Width() / 2, Height() / 2);
    DrawCircle(0, 0, 100, kColorGray, true);

    return true;
}
#include "CircleTest.h"

bool CircleTest::UserRender(int elapsed_time)
{
    ClearScreen();

    DrawCircle({ 0, 0 }, 100, kColorGray, true);
    Translate(WindowWidth() / 2, WindowHeight() / 2);
    DrawCircle({ 0, 0 }, 100, kColorGray, true);

    return true;
}
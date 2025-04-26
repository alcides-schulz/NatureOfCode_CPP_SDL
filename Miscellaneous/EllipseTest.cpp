#include "EllipseTest.h"

bool EllipseTest::Setup()
{
    return true;
}

bool EllipseTest::Draw()
{
    Background(255);
    Translate(0, Height() / 2);
    Stroke(kColorRed);
    StrokeWeight(2);
    Fill(127);
    for (int i = 1; i < 10; i++) {
        Ellipse((i - 1) * 100, 0, i * 10, i * 5);
    }

    return true;
}
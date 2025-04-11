#include "RectTest.h"

bool RectTest::Setup()
{
    //Background(255);

    //auto start = SDL_GetTicks();
    //Stroke(kColorRed);
    //Translate(Width() / 2, Height() / 2);

    //int r = 1;
    //for (int x = 2; x < 200; x++)
    //{
    //    for (int y = 2; y < 200; y++) {
    //        Circle(0, 0, r++, kColorBlack, true);
    //        if (r > Height() / 2)
    //            r = 1;
    //    }
    //}

    //cout << SDL_GetTicks() - start << endl;
    return true;
}

bool RectTest::Draw()
{
    Background(255);
    
    Stroke(kColorRed);
    StrokeWeight(1);
    Fill(127);

    Translate(Width() / 4, Height() / 2);
    Rotate(FrameCount() % 360 * M_PI / 180);
    RectMode(kRectCorner);
    Rect(0, 0, 40, 60);
    ResetMatrix();

    Translate(Width() / 2, Height() / 2);
    Rotate(FrameCount() % 360 * M_PI / 180);
    RectMode(kRectCenter);
    Rect(0, 0, 40, 60);
    ResetMatrix();

    Translate(Width() / 4 * 3, Height() / 2);
    RectMode(kRectCenter);
    int value = FrameCount() % 200;
    value = value > 100 ? 200 - value : value;
    Rect(0, 0, value, value);
    ResetMatrix();

    return true;
}
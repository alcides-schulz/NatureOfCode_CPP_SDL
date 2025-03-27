#include "CircleTest.h"

bool CircleTest::Setup()
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

bool CircleTest::Draw()
{
    Background(255);
    
    Stroke(kColorRed);
    StrokeWeight(2);
    Fill(127);
    for (int i = 1; i < 10; i++) {
        Circle(i * 100, Height() / 2, i * 10);
    }

    //Circle(0, 0, 100, kColorGray, true);
    //Translate(Width() / 2, Height() / 2);
    //Circle(0, 0, 100, kColorGray, true);

    return true;
}
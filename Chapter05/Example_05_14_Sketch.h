#ifndef EXAMPLE_05_14_SKETCH_H
#define EXAMPLE_05_14_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_05_example_14
{
    static float kPrecision = 0.5f;
    static float kInvPrecision = 1.0f / kPrecision;
    static int kPeriod = (int)floorf(360.0f * kInvPrecision);
    static float kDegToRad = (float)(M_PI / 180.0f);

    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 5.14: Sin/Cos Lookup Table", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void InitSinCos(void);
    private:
        vector<float>   _sin_table;
        vector<float>   _cos_table;
    };
}

#endif

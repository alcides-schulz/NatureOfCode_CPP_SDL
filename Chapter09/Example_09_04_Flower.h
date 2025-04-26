#ifndef EXAMPLE_09_04_FLOWER_H
#define EXAMPLE_09_04_FLOWER_H

#include "../Common/P5SDL.h"
#include "../Chapter09/Example_09_04_DNA.h"
#include "../Chapter09/Example_09_04_Rectangle.h"

namespace nature_of_code_chapter_09_example_04
{

#define F2C(f) ((Uint8)((f) * 255))

    class Flower
    {
    public:
        Flower(P5SDL *p5sdl, DNA *dna, int x, int y);
        void Show(void);
        void Rollover(int mouse_x, int mouse_y);
        float GetFitness(void) { return _fitness; };
        void DivideFitness(float total) { _fitness /= total; };
        DNA *GetDNA(void) { return _dna; };
    private:
        P5SDL *_p5sdl;
        bool _rollover_on;
        DNA *_dna;
        int _x;
        int _y;
        int _w;
        int _h;
        float _fitness;
        Rectangle *_bounding_box;
    };
}

#endif

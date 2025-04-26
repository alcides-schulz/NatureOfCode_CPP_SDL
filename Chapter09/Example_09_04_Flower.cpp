#include "Example_09_04_Flower.h"

namespace nature_of_code_chapter_09_example_04
{
    Flower::Flower(P5SDL *p5sdl, DNA *dna, int x, int y)
    {
        _p5sdl = p5sdl;
        _rollover_on = false;
        _dna = dna;
        _x = x;
        _y = y;
        _w = 70;
        _h = 140;
        _fitness = 1;
        _bounding_box = new Rectangle(p5sdl, _x - _w / 2, _y - _h / 2, _w, _h);
    }

    void Flower::Show(void)
    {
        auto genes = _dna->GetGenes();
        SDL_Color petal_color = { F2C(genes[0]), F2C(genes[1]), F2C(genes[2]), F2C(genes[3]) };
        int petal_size = (int)Utils::Map(genes[4], 0, 1, 4, 24);
        int petal_count = (int)Utils::Map(genes[5], 0, 1, 2, 16);
        SDL_Color center_color = { F2C(genes[6]), F2C(genes[7]), F2C(genes[8]), 255 };
        int center_size = (int)Utils::Map(genes[9], 0, 1, 24, 48);
        SDL_Color stem_color = { F2C(genes[10]), F2C(genes[11]), F2C(genes[12]), 255 };
        int stem_length = (int)Utils::Map(genes[13], 0, 1, 50, 100);

        _p5sdl->Push();
        _p5sdl->Translate(_x, _y);
        if (_rollover_on)
            _p5sdl->Fill(0, F2C(0.25f));
        else 
            _p5sdl->Fill(255);
        _p5sdl->Stroke(0);
        _p5sdl->StrokeWeight(1);
        _p5sdl->RectMode(kRectCenter);
        _p5sdl->Rect(0, 0, _w, _h);

        _p5sdl->Translate(0, _h / 2 - stem_length);
        _p5sdl->Stroke(stem_color);
        _p5sdl->StrokeWeight(4);
        _p5sdl->Line(0, 0, 0, stem_length);

        _p5sdl->Stroke(255);
        _p5sdl->Fill(petal_color);
        _p5sdl->StrokeWeight(0);
        for (int i = 0; i < petal_count; i++) {
            auto angle = (float)Utils::Map(i, 0, petal_count, 0, M_PI * 2);
            auto x = petal_size * cosf(angle);
            auto y = petal_size * sinf(angle);
            _p5sdl->Ellipse((int)x, (int)y, petal_size, petal_size);
        }
        
        _p5sdl->Fill(center_color);
        _p5sdl->StrokeWeight(0);
        _p5sdl->Ellipse(0, 0, center_size, center_size);

        _p5sdl->Pop();

        if (_rollover_on)
            _p5sdl->Fill(0);
        else 
            _p5sdl->Fill(F2C(0.25f));
        ostringstream fitness_formatted;
        fitness_formatted << std::fixed << std::setprecision(2) << _fitness;
        _p5sdl->Text(fitness_formatted.str(), _x - fitness_formatted.str().size(), _y + 90);
    }

    void Flower::Rollover(int mouse_x, int mouse_y)
    {
        if (_bounding_box->Contains(mouse_x, mouse_y))
            _rollover_on = true, _fitness += 0.25f;
        else
            _rollover_on = false;
    }

}

// END

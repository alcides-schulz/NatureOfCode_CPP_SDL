#include "Example_08_09_Sketch.h"

namespace nature_of_code_chapter_08_example_09
{
    bool Sketch::Setup(void)
    {
        map<char, string> rules;
        rules['F'] = "FF+[+F-F-F]-[-F+F+F]";

        _lsystem = new LSystem("F", rules);
        _turtle = new Turtle(this, 4, 25 * (M_PI / 180));

        for (int i = 0; i < 4; i++) {
            _lsystem->Generate();
        }

        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        Translate(Width() / 2, Height());
        _turtle->Render(_lsystem->GetSentence());

        return true;
    }

    void Sketch::Cleanup(void)
    {
        delete _lsystem;
        delete _turtle;
    }
}

// END

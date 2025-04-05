#include "Example_08_08_Sketch.h"

namespace nature_of_code_chapter_08_example_08
{
    bool Sketch::Setup(void)
    {
        Background(255);

        _current = "A";
        for (int i = 0; i < 9; i++) {
            Generate();
            Text(to_string(i) + ": " + _current, 4, i * 16);
        }

        NoLoop();
        return true;
    }

    void Sketch::Generate(void)
    {
        string next = "";
        for (int i = 0; i < _current.length(); i++) {
            auto c = _current[i];
            if (c == 'A')
                next += "AB";
            else if (c == 'B')
                next += "A";
        }
        _current = next;
    }
 
}

// END

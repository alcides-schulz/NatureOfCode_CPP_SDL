#include "Example_03_07_Sketch.h"

namespace nature_of_code_chapter_03_example_07
{
    bool Sketch::Setup(void)
    {
        for (int i = 0; i < 10; i++) {
            _oscillators.push_back(new Oscillator(this));
        }
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        for (int i = 0; i < _oscillators.size(); i++) {
            _oscillators[i]->Update();
            _oscillators[i]->Show(this);
        }
    
        return true;
    }
    
}

// END

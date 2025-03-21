#include "Example_03_07_Sketch.h"

namespace nature_of_code_chapter_03_example_07
{
    bool Sketch::Setup(void)
    {
        for (int i = 0; i < 10; i++) {
            oscillators_.push_back(new Oscillator(this));
        }
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        ClearScreen();
    
        for (int i = 0; i < oscillators_.size(); i++) {
            oscillators_[i]->Update();
            oscillators_[i]->Show(this);
        }
    
        return true;
    }
    
}

// END

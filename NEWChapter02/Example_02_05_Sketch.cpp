#include "Example_02_05_Sketch.h"
#include "../Common/Utils.h"
namespace nature_of_code_chapter_02_example_05
{
    
    bool Sketch::Setup()
    {
        liquid_ = new Liquid(0, Height() / 2, Width(), Height() / 2, 0.1f);
        for (int i = 0; i < std::size(mover_); i++) {
            mover_[i] = nullptr;
        }
        Reset();
        return true;
    }
    
    bool Sketch::Draw()
    {
        ClearScreen();
    
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            Reset();
        }
        liquid_->Show(this);
        for (int i = 0; i < std::size(mover_); i++) {
            if (liquid_->Contains(mover_[i])) {
                auto dragForce = liquid_->CalculateDrag(mover_[i]);
                mover_[i]->ApplyForce(dragForce);
            }
            PVector gravity(0.0f, 0.1f);
            gravity.Mult((float)mover_[i]->GetMass());
            mover_[i]->ApplyForce(gravity);
            mover_[i]->Update();
            mover_[i]->CheckEdges(this);
            mover_[i]->Show(this);
        }
    
        return true;
    }
    
    void Sketch::Reset(void)
    {
        for (int i = 0; i < std::size(mover_); i++) {
            if (mover_[i] != nullptr) {
                delete mover_[i];
            }
            mover_[i] = new Mover(PVector(40 + i * 70, 0), (int)(Utils::Random(1, 4)));
        }
    }
    
}

// END

#include "Example_1_7.h"
#include "../Common/Utils.h"

bool Example_1_7::Setup()
{
    auto location = PVector(Utils::Random((float)Width()), Utils::Random((float)Height()));
    auto velocity = PVector(Utils::Random(-2, 2), Utils::Random(-2, 2));
    mover_ = new Mover_1_7(location, velocity);

    return true;
}

bool Example_1_7::Draw()
{
    ClearScreen();

    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Show(this);

    return true;
}

//END

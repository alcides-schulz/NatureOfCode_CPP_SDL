#include "Example_4_1.h"
#include "../Common/Utils.h"

bool Example_4_1::Setup(void)
{
    for (int i = 0; i < 20; i++)
        cout << Utils::Random(-1, 1) << endl;
    return true;
}

bool Example_4_1::Draw(void)
{
    ClearScreen();

    return true;
}

// END

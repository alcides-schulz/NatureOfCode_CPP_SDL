#ifndef EXAMPLE_1_7_H
#define EXAMPLE_1_7_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "../Chapter01/Chapter01MoverV1.h"

#include <cstdlib>
#include <time.h>

class Example_1_7 : public SDL_Framework
{
public:
    Example_1_7() : SDL_Framework("Example 1.7: Motion 101 (velocity)", 400, 100, 1200, 800, 0) {}
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Chapter01MoverV1 *mover_;
};

#endif

//END

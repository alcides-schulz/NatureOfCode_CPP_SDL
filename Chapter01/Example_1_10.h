#ifndef EXAMPLE_1_10_H
#define EXAMPLE_1_10_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "../Chapter01/Chapter01MoverV1.h"

class Example_1_10 : public SDL_Framework
{
public:
    Example_1_10() : SDL_Framework("Example 1.10: Accelerating Toward the Mouse", 400, 100, 1200, 800, 0) {}
    bool UserInit() override;
    bool UserRender(int elapsed_time) override;
private:
    Chapter01MoverV1 *mover_;
};

#endif

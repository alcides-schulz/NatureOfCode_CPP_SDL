#ifndef EXAMPLE_4_4_H
#define EXAMPLE_4_4_H

#include "../Common/SDL_Framework.h"
#include "Emitter_4_4.h"

class Example_4_4 : public SDL_Framework
{
public:
    Example_4_4() : SDL_Framework("Example 4.4: A System of Systems", -1, -1, 640, 240, 0) {};
    bool Setup(void) override;
    bool Draw(void) override;
private:
    vector<Emitter_4_4 *>   emitters_;
};

#endif

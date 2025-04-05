#ifndef COPY_EXAMPLE_H
#define COPY_EXAMPLE_H

#include "../Common/P5SDL.h"

#define COPY_CHAPTER "08"
#define COPY_FROM_EXAMPLE "06"
#define COPY_TO_EXAMPLE "07"

#define COPY_FOLDER ".\\Chapter" COPY_CHAPTER
#define COPY_FROM_NUMBER COPY_CHAPTER "_" COPY_FROM_EXAMPLE
#define COPY_TO_NUMBER COPY_CHAPTER "_" COPY_TO_EXAMPLE

#define COPY_TITLE "Copy Example Folder: " COPY_FOLDER " From: '" COPY_FROM_NUMBER "' To: '" COPY_TO_NUMBER "'"

class CopyExample : public P5SDL
{
public:
    CopyExample() : P5SDL(COPY_TITLE, -1, -1, 640, 240, 0) {}
    bool Setup(void) override;
    bool Draw() override { return false; };
};

#endif


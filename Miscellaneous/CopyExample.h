#ifndef COPY_EXAMPLE_H
#define COPY_EXAMPLE_H

#include "../Common/P5SDL.h"

#define CHAPTER "05"
#define FROM_EXAMPLE "11"
#define TO_EXAMPLE "12"

#define COPY_FOLDER ".\\Chapter" CHAPTER
#define FROM_NUMBER CHAPTER "_" FROM_EXAMPLE
#define TO_NUMBER CHAPTER "_" TO_EXAMPLE

#define COPY_TITLE "Copy Example Folder: " COPY_FOLDER " From: '" FROM_NUMBER "' To: '" TO_NUMBER "'"

class CopyExample : public P5SDL
{
public:
    CopyExample() : P5SDL(COPY_TITLE, -1, -1, 640, 240, 0) {}
    bool Setup(void) override;
    bool Draw() override { return false; };
};

#endif


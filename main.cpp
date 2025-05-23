//-------------------------------------------------------------------------------------------------
//  Nature of Code menu
//-------------------------------------------------------------------------------------------------

//TODO: review perlin noise to make it close to p5
//TODO: implement beginShape/endShape and Fill ??
//TODO: implement noStroke() (5.12)
//TODO: create p5.Point: 5.13, quadtree.cpp, 5.14

#include "Common/P5SDL.h"

#include "Chapter01/Example_01_01_Sketch.h"
#include "Chapter01/Example_01_02_Sketch.h"
#include "Chapter01/Example_01_03_Sketch.h"
#include "Chapter01/Example_01_04_Sketch.h"
#include "Chapter01/Example_01_05_Sketch.h"
#include "Chapter01/Example_01_06_Sketch.h"
#include "Chapter01/Example_01_07_Sketch.h"
#include "Chapter01/Example_01_08_Sketch.h"
#include "Chapter01/Example_01_09_Sketch.h"
#include "Chapter01/Example_01_10_Sketch.h"

#include "Chapter02/Example_02_01_Sketch.h"
#include "Chapter02/Example_02_02_Sketch.h"
#include "Chapter02/Example_02_03_Sketch.h"
#include "Chapter02/Example_02_04_Sketch.h"
#include "Chapter02/Example_02_05_Sketch.h"
#include "Chapter02/Example_02_06_Sketch.h"
#include "Chapter02/Example_02_07_Sketch.h"
#include "Chapter02/Example_02_08_Sketch.h"
#include "Chapter02/Example_02_09_Sketch.h"

#include "Chapter03/Example_03_01_Sketch.h"
#include "Chapter03/Example_03_02_Sketch.h"
#include "Chapter03/Example_03_03_Sketch.h"
#include "Chapter03/Example_03_04_Sketch.h"
#include "Chapter03/Example_03_05_Sketch.h"
#include "Chapter03/Example_03_06_Sketch.h"
#include "Chapter03/Example_03_07_Sketch.h"
#include "Chapter03/Example_03_08_Sketch.h"
#include "Chapter03/Example_03_09_Sketch.h"
#include "Chapter03/Example_03_10_Sketch.h"
#include "Chapter03/Example_03_11_Sketch.h"

#include "Chapter04/Example_04_01_Sketch.h"
#include "Chapter04/Example_04_02_Sketch.h"
#include "Chapter04/Example_04_03_Sketch.h"
#include "Chapter04/Example_04_04_Sketch.h"
#include "Chapter04/Example_04_05_Sketch.h"
#include "Chapter04/Example_04_06_Sketch.h"
#include "Chapter04/Example_04_07_Sketch.h"
#include "Chapter04/Example_04_08_Sketch.h"

#include "Chapter05/Example_05_01_Sketch.h"
#include "Chapter05/Example_05_02_Sketch.h"
#include "Chapter05/Example_05_03_Sketch.h"
#include "Chapter05/Example_05_04_Sketch.h"
#include "Chapter05/Example_05_05_Sketch.h"
#include "Chapter05/Example_05_06_Sketch.h"
#include "Chapter05/Example_05_07_Sketch.h"
#include "Chapter05/Example_05_08_Sketch.h"
#include "Chapter05/Example_05_09_Sketch.h"
#include "Chapter05/Example_05_10_Sketch.h"
#include "Chapter05/Example_05_11_Sketch.h"
#include "Chapter05/Example_05_12_Sketch.h"
#include "Chapter05/Example_05_13_Sketch.h"
#include "Chapter05/Example_05_14_Sketch.h"

#include "Chapter07/Example_07_01_Sketch.h"
#include "Chapter07/Example_07_02_Sketch.h"
#include "Chapter07/Example_07_03_Sketch.h"

#include "Chapter08/Example_08_01_Sketch.h"
#include "Chapter08/Example_08_02_Sketch.h"
#include "Chapter08/Example_08_03_Sketch.h"
#include "Chapter08/Example_08_04_Sketch.h"
#include "Chapter08/Example_08_05_Sketch.h"
#include "Chapter08/Example_08_06_Sketch.h"
#include "Chapter08/Example_08_07_Sketch.h"
#include "Chapter08/Example_08_08_Sketch.h"
#include "Chapter08/Example_08_09_Sketch.h"

#include "Chapter09/Example_09_01_Sketch.h"
#include "Chapter09/Example_09_02_Sketch.h"
#include "Chapter09/Example_09_03_Sketch.h"
#include "Chapter09/Example_09_04_Sketch.h"
#include "Chapter09/Example_09_05_Sketch.h"

#include "Miscellaneous/CircleTest.h"
#include "Miscellaneous/GenerateExampleInitialCode.h"
#include "Miscellaneous/CopyExample.h"
#include "Miscellaneous/RectTest.h"
#include "Miscellaneous/EllipseTest.h"

using namespace std;

vector<P5SDL *> chapter01_menu = {
    new nature_of_code_chapter_01_example_01::Sketch(),
    new nature_of_code_chapter_01_example_02::Sketch(),
    new nature_of_code_chapter_01_example_03::Sketch(),
    new nature_of_code_chapter_01_example_04::Sketch(),
    new nature_of_code_chapter_01_example_05::Sketch(),
    new nature_of_code_chapter_01_example_06::Sketch(),
    new nature_of_code_chapter_01_example_07::Sketch(),
    new nature_of_code_chapter_01_example_08::Sketch(),
    new nature_of_code_chapter_01_example_09::Sketch(),
    new nature_of_code_chapter_01_example_10::Sketch(),
};
vector<P5SDL *> chapter02_menu = {
    new nature_of_code_chapter_02_example_01::Sketch(),
    new nature_of_code_chapter_02_example_02::Sketch(),
    new nature_of_code_chapter_02_example_03::Sketch(),
    new nature_of_code_chapter_02_example_04::Sketch(),
    new nature_of_code_chapter_02_example_05::Sketch(),
    new nature_of_code_chapter_02_example_06::Sketch(),
    new nature_of_code_chapter_02_example_07::Sketch(),
    new nature_of_code_chapter_02_example_08::Sketch(),
    new nature_of_code_chapter_02_example_09::Sketch(),
};
vector<P5SDL *> chapter03_menu = {
    new nature_of_code_chapter_03_example_01::Sketch(),
    new nature_of_code_chapter_03_example_02::Sketch(),
    new nature_of_code_chapter_03_example_03::Sketch(),
    new nature_of_code_chapter_03_example_04::Sketch(),
    new nature_of_code_chapter_03_example_05::Sketch(),
    new nature_of_code_chapter_03_example_06::Sketch(),
    new nature_of_code_chapter_03_example_07::Sketch(),
    new nature_of_code_chapter_03_example_08::Sketch(),
    new nature_of_code_chapter_03_example_09::Sketch(),
    new nature_of_code_chapter_03_example_10::Sketch(),
    new nature_of_code_chapter_03_example_11::Sketch(),
};
vector<P5SDL *> chapter04_menu = {
    new nature_of_code_chapter_04_example_01::Sketch(),
    new nature_of_code_chapter_04_example_02::Sketch(),
    new nature_of_code_chapter_04_example_03::Sketch(),
    new nature_of_code_chapter_04_example_04::Sketch(),
    new nature_of_code_chapter_04_example_05::Sketch(),
    new nature_of_code_chapter_04_example_06::Sketch(),
    new nature_of_code_chapter_04_example_07::Sketch(),
    new nature_of_code_chapter_04_example_08::Sketch(),
};
vector<P5SDL *> chapter05_menu = {
    new nature_of_code_chapter_05_example_01::Sketch(),
    new nature_of_code_chapter_05_example_02::Sketch(),
    new nature_of_code_chapter_05_example_03::Sketch(),
    new nature_of_code_chapter_05_example_04::Sketch(),
    new nature_of_code_chapter_05_example_05::Sketch(),
    new nature_of_code_chapter_05_example_06::Sketch(),
    new nature_of_code_chapter_05_example_07::Sketch(),
    new nature_of_code_chapter_05_example_08::Sketch(),
    new nature_of_code_chapter_05_example_09::Sketch(),
    new nature_of_code_chapter_05_example_10::Sketch(),
    new nature_of_code_chapter_05_example_11::Sketch(),
    new nature_of_code_chapter_05_example_12::Sketch(),
    new nature_of_code_chapter_05_example_13::Sketch(),
    new nature_of_code_chapter_05_example_14::Sketch(),
};
vector<P5SDL *> chapter07_menu = {
    new nature_of_code_chapter_07_example_01::Sketch(),
    new nature_of_code_chapter_07_example_02::Sketch(),
    new nature_of_code_chapter_07_example_03::Sketch(),
};
vector<P5SDL *> chapter08_menu = {
    new nature_of_code_chapter_08_example_01::Sketch(),
    new nature_of_code_chapter_08_example_02::Sketch(),
    new nature_of_code_chapter_08_example_03::Sketch(),
    new nature_of_code_chapter_08_example_04::Sketch(),
    new nature_of_code_chapter_08_example_05::Sketch(),
    new nature_of_code_chapter_08_example_06::Sketch(),
    new nature_of_code_chapter_08_example_07::Sketch(),
    new nature_of_code_chapter_08_example_08::Sketch(),
    new nature_of_code_chapter_08_example_09::Sketch(),
};
vector<P5SDL *> chapter09_menu = {
    new nature_of_code_chapter_09_example_01::Sketch(),
    new nature_of_code_chapter_09_example_02::Sketch(),
    new nature_of_code_chapter_09_example_03::Sketch(),
    new nature_of_code_chapter_09_example_04::Sketch(),
    new nature_of_code_chapter_09_example_05::Sketch(),
};

vector<P5SDL *> miscellaneous = {
    new CircleTest(),
    new RectTest(),
    new EllipseTest(),
    new GenerateExampleInitialCode(),
    new CopyExample(),
};

void ShowMenu(vector<P5SDL *> chapter_menu)
{
    while (true) {
        cout << "Menu" << endl << endl;
        for (int i = 0; i < chapter_menu.size(); i++) {
            cout << "\t " << (char)('a' + i) << ". " << chapter_menu[i]->WindowTitle() << endl;
        }
        cout << endl << "\t x. Exit" << endl << endl << "--> ";
        string response;
        getline(cin, response);
        if (response.compare("x") == 0) {
            break;
        }
        for (int i = 0; i < chapter_menu.size(); i++) {
            string selection(1, ('a' + i));
            if (response.compare(selection) == 0) {
                if (chapter_menu[i]->Init()) {
                    chapter_menu[i]->Run();
                }
                break;
            }
        }
    }
}

void ShowSDLVersion(void)
{
    int result = SDL_Init(SDL_INIT_EVERYTHING);
    if (result != 0) {
        std::cout << "SDL_Init failed, result: " << result << ".\n";
        std::getchar();
        return;
    }
    SDL_version compiled;
    SDL_version linked;
    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);
    cout << "Compiled SDL version " << (int)compiled.major << "." << (int)compiled.minor << "." << (int)compiled.patch << std::endl;
    cout << "Linked SDL version " << (int)linked.major << "." << (int)linked.minor << "." << (int)linked.patch << std::endl;
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    ShowSDLVersion();

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    string response;
    while (true) {
        cout << endl << "Nature of Code Menu" << endl;
        cout << endl << "\t a. Chapter 1 - Vectors";
        cout << endl << "\t b. Chapter 2 - Forces";
        cout << endl << "\t c. Chapter 3 - Oscillation";
        cout << endl << "\t d. Chapter 4 - Particle System";
        cout << endl << "\t e. Chapter 5 - Autonomous Agents";
        cout << endl << "\t f. Chapter 7 - Cellular Automata";
        cout << endl << "\t g. Chapter 8 - Fractals";
        cout << endl << "\t h. Chapter 9 - Evolutionary Computing";
        cout << endl;
        cout << endl << "\t z. Miscellaneous (development and test code)";
        cout << endl << "\t x. Exit" << endl << endl << "--> ";
        getline(cin, response);
        if (response.compare("x") == 0) {
            break;
        }
        if (response.compare("a") == 0) {
            ShowMenu(chapter01_menu);
            continue;
        }
        if (response.compare("b") == 0) {
            ShowMenu(chapter02_menu);
            continue;
        }
        if (response.compare("c") == 0) {
            ShowMenu(chapter03_menu);
            continue;
        }
        if (response.compare("d") == 0) {
            ShowMenu(chapter04_menu);
            continue;
        }
        if (response.compare("e") == 0) {
            ShowMenu(chapter05_menu);
            continue;
        }
        if (response.compare("f") == 0) {
            ShowMenu(chapter07_menu);
            continue;
        }
        if (response.compare("g") == 0) {
            ShowMenu(chapter08_menu);
            continue;
        }
        if (response.compare("h") == 0) {
            ShowMenu(chapter09_menu);
            continue;
        }
        if (response.compare("z") == 0) {
            ShowMenu(miscellaneous);
            continue;
        }
    }
    return 0;
}

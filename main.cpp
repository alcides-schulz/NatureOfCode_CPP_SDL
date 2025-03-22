//-------------------------------------------------------------------------------------------------
//  Nature of Code menu
//-------------------------------------------------------------------------------------------------

#include "Common/SDL_Framework.h"

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

#include "Tests/CircleTest.h"
#include "Tests/GenerateExampleInitialCode.h"

using namespace std;

vector<SDL_Framework *> chapter01_menu = {
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
vector<SDL_Framework *> chapter02_menu = {
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
vector<SDL_Framework *> chapter03_menu = {
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

vector<SDL_Framework *> chapter04_menu = {
    new nature_of_code_chapter_04_example_01::Sketch(),
    new nature_of_code_chapter_04_example_02::Sketch(),
    new nature_of_code_chapter_04_example_03::Sketch(),
    new nature_of_code_chapter_04_example_04::Sketch(),
    new nature_of_code_chapter_04_example_05::Sketch(),
    new nature_of_code_chapter_04_example_06::Sketch(),
    new nature_of_code_chapter_04_example_07::Sketch(),
    new nature_of_code_chapter_04_example_08::Sketch(),
};

vector<SDL_Framework *> tests_menu = {
    new CircleTest(),
    new GenerateExampleInitialCode(),
};

void ShowMenu(vector<SDL_Framework *> chapter_menu)
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

int main(int argc, char* argv[])
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    string response;
    while (true) {
        cout << "Nature of Code Menu" << endl;
        cout << endl << "\t a. Chapter 1 - Vectors";
        cout << endl << "\t b. Chapter 2 - Forces";
        cout << endl << "\t c. Chapter 3 - Oscillation";
        cout << endl << "\t d. Chapter 4 - Particle System";
        cout << endl;
        cout << endl << "\t z. Tests";
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
        if (response.compare("z") == 0) {
            ShowMenu(tests_menu);
            continue;
        }
    }
    return 0;
}

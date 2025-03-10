//-------------------------------------------------------------------------------------------------
//  Nature of Code menu
//-------------------------------------------------------------------------------------------------

#include "Common/SDL_Framework.h"

#include "Chapter01/Example_1_1.h"
#include "Chapter01/Example_1_2.h"
#include "Chapter01/Example_1_3.h"
#include "Chapter01/Example_1_4.h"
#include "Chapter01/Example_1_5.h"
#include "Chapter01/Example_1_6.h"
#include "Chapter01/Example_1_7.h"
#include "Chapter01/Example_1_8.h"
#include "Chapter01/Example_1_9.h"
#include "Chapter01/Example_1_10.h"

#include "Chapter02/Example_2_1.h"
#include "Chapter02/Example_2_2.h"
#include "Chapter02/Example_2_3.h"
#include "Chapter02/Example_2_4.h"
#include "Chapter02/Example_2_5.h"
#include "Chapter02/Example_2_6.h"
#include "Chapter02/Example_2_7.h"
#include "Chapter02/Example_2_8.h"
#include "Chapter02/Example_2_9.h"

#include "Chapter03/Example_3_1.h"
#include "Chapter03/Example_3_2.h"

#include "Tests/CircleTest.h"

using namespace std;

vector<SDL_Framework *> chapter01_menu = {
    new Example_1_1(),
    new Example_1_2(),
    new Example_1_3(),
    new Example_1_4(),
    new Example_1_5(),
    new Example_1_6(),
    new Example_1_7(),
    new Example_1_8(),
    new Example_1_9(),
    new Example_1_10(),
};
vector<SDL_Framework *> chapter02_menu = {
    new Example_2_1(),
    new Example_2_2(),
    new Example_2_3(),
    new Example_2_4(),
    new Example_2_5(),
    new Example_2_6(),
    new Example_2_7(),
    new Example_2_8(),
    new Example_2_9(),
};
vector<SDL_Framework *> chapter03_menu = {
    new Example_3_1(),
    new Example_3_2(),
};

vector<SDL_Framework *> tests_menu = {
    new CircleTest(),
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
    string response;
    while (true) {
        cout << "Nature of Code Menu" << endl;
        cout << endl << "\t a. Chapter 1 - Vectors";
        cout << endl << "\t b. Chapter 2 - Forces";
        cout << endl << "\t c. Chapter 3 - Oscillation";
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
        if (response.compare("z") == 0) {
            ShowMenu(tests_menu);
            continue;
        }
    }
    return 0;
}

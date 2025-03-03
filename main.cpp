//-------------------------------------------------------------------------------------------------
//  SDL Programming menu
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

using namespace std;

vector<SDL_Framework *> noc_chapter01_menu = {
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
vector<SDL_Framework *> noc_chapter02_menu = {
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

void NatureOfCodeChapterMenu(vector<SDL_Framework *> chapter_menu)
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
    while (true) {
        cout << "Nature of Code Menu" << endl;
        cout << endl << "\t a. Chapter 1 - Vectors";
        cout << endl << "\t b. Chapter 2 - Forces";
        cout << endl << "\t x. Exit" << endl << endl << "--> ";
        string response;
        getline(cin, response);
        if (response.compare("x") == 0) {
            break;
        }
        if (response.compare("a") == 0) {
            NatureOfCodeChapterMenu(noc_chapter01_menu);
            continue;
        }
        if (response.compare("b") == 0) {
            NatureOfCodeChapterMenu(noc_chapter02_menu);
            continue;
        }
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------
//  SDL Programming menu
//-------------------------------------------------------------------------------------------------

#include "SDL_Framework.h"

#include "TheNatureOfCode/Chapter01/Example_1_1.h"
#include "TheNatureOfCode/Chapter01/Example_1_2.h"
#include "TheNatureOfCode/Chapter01/Example_1_3.h"
#include "TheNatureOfCode/Chapter01/Example_1_4.h"
#include "TheNatureOfCode/Chapter01/Example_1_5.h"
#include "TheNatureOfCode/Chapter01/Example_1_6.h"
#include "TheNatureOfCode/Chapter01/Example_1_7.h"
#include "TheNatureOfCode/Chapter01/Example_1_8.h"
#include "TheNatureOfCode/Chapter01/Example_1_9.h"
#include "TheNatureOfCode/Chapter01/Example_1_10.h"

#include "TheNatureOfCode/Chapter02/Example_2_1.h"
#include "TheNatureOfCode/Chapter02/Example_2_2.h"
#include "TheNatureOfCode/Chapter02/Example_2_3.h"
#include "TheNatureOfCode/Chapter02/Example_2_4.h"
#include "TheNatureOfCode/Chapter02/Example_2_5.h"
#include "TheNatureOfCode/Chapter02/Example_2_6.h"
#include "TheNatureOfCode/Chapter02/Example_2_7.h"
#include "TheNatureOfCode/Chapter02/Example_2_8.h"
#include "TheNatureOfCode/Chapter02/Example_2_9.h"

using namespace std;

vector<SDL_Framework *> noc_chapter01_menu;
vector<SDL_Framework *> noc_chapter02_menu;

void InitNatureOfCodeMenus()
{
    // chapter 01
    noc_chapter01_menu.push_back(new Example_1_1());
    noc_chapter01_menu.push_back(new Example_1_2());
    noc_chapter01_menu.push_back(new Example_1_3());
    noc_chapter01_menu.push_back(new Example_1_4());
    noc_chapter01_menu.push_back(new Example_1_5());
    noc_chapter01_menu.push_back(new Example_1_6());
    noc_chapter01_menu.push_back(new Example_1_7());
    noc_chapter01_menu.push_back(new Example_1_8());
    noc_chapter01_menu.push_back(new Example_1_9());
    noc_chapter01_menu.push_back(new Example_1_10());
    // chapter 02
    noc_chapter02_menu.push_back(new Example_2_1());
    noc_chapter02_menu.push_back(new Example_2_2());
    noc_chapter02_menu.push_back(new Example_2_3());
    noc_chapter02_menu.push_back(new Example_2_4());
    noc_chapter02_menu.push_back(new Example_2_5());
    noc_chapter02_menu.push_back(new Example_2_6());
    noc_chapter02_menu.push_back(new Example_2_7());
    noc_chapter02_menu.push_back(new Example_2_8());
    noc_chapter02_menu.push_back(new Example_2_9());
}

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
    InitNatureOfCodeMenus();
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

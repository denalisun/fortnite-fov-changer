#include <iostream>
#include <Windows.h>
#include <cmath>
#include <tuple>

#include "ini.h"

using namespace std;

namespace MenuBase
{
    char* path = strcat(getenv("LOCALAPPDATA"), "\\FortniteGame\\Saved\\Config\\WindowsClient\\GameUserSettings.ini");
    int fovNum = 80;
    int fovList[56] = {1080, 1060, 1040, 1020, 1000, 990, 970, 950, 930, 920, 910, 890, 870, 860, 840, 830, 810, 800, 780, 770, 760, 750, 730, 720, 710, 690, 680, 670, 660, 650, 630, 620, 610, 600, 590, 580, 570, 550, 540, 530, 520, 510, 500, 490, 480, 470, 460, 450, 440, 430, 420, 410, 400, 390, 385, 375};

    void GetConsoleSize(int& cols, int& rows)
    {
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }

    void printTo(string toPrint, int x, int y)
    {
        cout << "\033[" << y << ";" << x << "H" << toPrint;
    }

    void printCentered(string toPrint, int y)
    {
        int cols, rows;
        GetConsoleSize(cols, rows);

        int x = floor((cols - toPrint.length()) / 2);
        cout << "\033[" << y << ";" << x << "H" << toPrint;
    }

    void printSelected(string toPrint, int y, bool isSelected = false)
    {
        int cols, rows;
        GetConsoleSize(cols, rows);

        if (isSelected == true)
        {
            int x = floor((cols - toPrint.length()) / 2);
            cout << "\033[" << y << ";" << x - 2 << "H" << "\033[30;47m" << "  " << toPrint << "  " << "\033[0m";
        }
        else
        {
            int x = floor((cols - toPrint.length()) / 2);
            cout << "\033[" << y << ";" << x - 2 << "H" << "  " << toPrint << "  ";
        }
    }

    void DrawMenu(int iPage, int& iSelection)
    {
        int cols, rows;

        switch (iPage)
        {
            case 0:
                printCentered("Fortnite FOV Changer", 1);
                
                if (iSelection == 1) { printSelected("Preset FOV", 4, true); } else { printSelected("Preset FOV", 4);/*cout << "  Preset FOV" << endl;*/ }
                if (iSelection == 2) { printSelected("Custom FOV", 5, true); } else { printSelected("Custom FOV", 5); }
                if (iSelection == 3) { printSelected("Exit", 6, true); } else { printSelected("Exit", 6); }

                GetConsoleSize(cols, rows);

                printTo("Made by Zenn", 1, rows);

                break;

            case 1:
                printCentered("Fortnite FOV Changer", 1);

                if (iSelection == 1) { printSelected("80 FOV", 4, true); } else { printSelected("80 FOV", 4); }
                if (iSelection == 2) { printSelected("90 FOV", 5, true); } else { printSelected("90 FOV", 5); }
                if (iSelection == 3) { printSelected("100 FOV", 6, true); } else { printSelected("100 FOV", 6); }
                if (iSelection == 4) { printSelected("110 FOV", 7, true); } else { printSelected("110 FOV", 7); }
                if (iSelection == 5) { printSelected("120 FOV", 8, true); } else { printSelected("120 FOV", 8); }
                if (iSelection == 6) { printSelected("135 FOV", 9, true); } else { printSelected("135 FOV", 9); }
                if (iSelection == 7) { printSelected("Exit", 11, true); } else { printSelected("Exit", 11); }

                GetConsoleSize(cols, rows);

                printTo("Made by Zenn", 1, rows);

                break;

            case 2:
                printCentered("Fortnite FOV Changer", 1);

                GetConsoleSize(cols, rows);

                printCentered("-- < " + to_string(fovNum) + " > ++", floor(rows / 2));
                printTo("Made by Zenn", 1, rows);

                break;

        }
    }

    void MenuHandler(int iPage, int& iSelection)
    {
        DrawMenu(iPage, iSelection);

        while (true)
        {
            if (GetAsyncKeyState(VK_DOWN) & 1)
            {
                ++iSelection;
                
                if (iPage == 0)
                {
                    if (iSelection > 3)
                    {
                        iSelection = 1;
                    }
                } 
                else if (iPage == 1)
                {
                    if (iSelection > 7)
                    {
                        iSelection = 1;
                    }
                }

                MenuHandler(iPage, iSelection);

            }

            if (GetAsyncKeyState(VK_UP) & 1)
            {
                --iSelection;

                if (iPage == 0)
                {
                    if (iSelection < 1)
                    {
                        iSelection = 3;
                    }
                } 
                else if (iPage == 1)
                {
                    if (iSelection <= 0)
                    {
                        iSelection = 7;
                    }
                }

                MenuHandler(iPage, iSelection);
            }

            if (GetAsyncKeyState(VK_SPACE) & 1)
            {
                if (iPage == 0) // Main Menu
                {
                    switch(iSelection) // Navigate around menus
                    {
                        case 1:
                            iPage = 1;
                            iSelection = 1;

                            cout << "\033[2J\033[1;1H";
                            MenuHandler(iPage, iSelection);

                            break;

                        case 2:
                            iPage = 2;
                            iSelection = 0;
                            cout << "\033[2J\033[1;1H";
                            MenuHandler(iPage, iSelection);

                            break;
                        
                        case 3:
                            exit(0);

                            break;
                    }
                }
                else if (iPage == 1) // Preset FOV Menu
                {

                    switch(iSelection) // Check what option was selected, and set the resolution in the GameUserSettings file.
                    {
                        case 1:
                            IniEditor::WriteResolution("1080", path);
                            break;

                        case 2:
                            IniEditor::WriteResolution("910", path);
                            break;

                        case 3:
                            IniEditor::WriteResolution("760", path);
                            break;

                        case 4:
                            IniEditor::WriteResolution("630", path);
                            break;

                        case 5:
                            IniEditor::WriteResolution("520", path);
                            break;
                        
                        case 6:
                            IniEditor::WriteResolution("375", path);
                            break;
                        
                        case 7:
                            iPage = 0;
                            iSelection = 1;

                            cout << "\033[2J\033[1;1H";
                            MenuHandler(iPage, iSelection);
                            break;
                    }
                }
                else if (iPage == 2)
                {
                    IniEditor::WriteResolution(string(to_string(fovList[fovNum - 80])).c_str(), path);
                    iPage = 0;
                    iSelection = 1;
                    
                    cout << "\033[2J\033[1;1H";
                    MenuHandler(iPage, iSelection);
                }
            }

            if (iPage == 2) // Custom FOV Menu
            {
                if (GetAsyncKeyState(VK_RIGHT) & 1) // If Right Arrow is pressed, add 1 to fovNum and redraw screen
                {
                    ++fovNum;
                    MenuHandler(iPage, iSelection);
                }
                
                if (GetAsyncKeyState(VK_LEFT) & 1) // If Left Arrow is pressed, subtract 1 from fovNum and redraw screen
                {
                    --fovNum;
                    MenuHandler(iPage, iSelection);
                }
            }
        }
    }
}

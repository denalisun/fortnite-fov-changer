#include <iostream>
#include <Windows.h>
#include <cmath>
#include <tuple>

#include "ini.h"

using namespace std;

namespace MenuBase
{
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

    void DrawMenu(int iPage, int& iSelection)
    {
        switch (iPage)
        {
            case 0: {
                printCentered("Fortnite FOV Changer", 1);
                
                if (iSelection == 1) { printCentered("[ Preset FOV ]", 4);/*cout << "> Preset FOV" << endl;*/ } else { printCentered("  Preset FOV  ", 4);/*cout << "  Preset FOV" << endl;*/ }
                if (iSelection == 2) { printCentered("[ Custom FOV ]", 5); } else { printCentered("  Custom FOV  ", 5); }
                if (iSelection == 3) { printCentered("[ Exit ]", 6); } else { printCentered("  Exit  ", 6); }

                int cols, rows;
                GetConsoleSize(cols, rows);

                printTo("Made by Zenn", 0, rows);

                break;
            }

            case 1: {
                printCentered("Fortnite FOV Changer", 1);

                if (iSelection == 1) { printCentered("[ 80 FOV ]", 4); } else { printCentered("  80 FOV  ", 4); }
                if (iSelection == 2) { printCentered("[ 90 FOV ]", 5); } else { printCentered("  90 FOV  ", 5); }
                if (iSelection == 3) { printCentered("[ 100 FOV ]", 6); } else { printCentered("  100 FOV  ", 6); }
                if (iSelection == 4) { printCentered("[ 110 FOV ]", 7); } else { printCentered("  110 FOV  ", 7); }
                if (iSelection == 5) { printCentered("[ 120 FOV ]", 8); } else { printCentered("  120 FOV  ", 8); }
                if (iSelection == 6) { printCentered("[ 135 FOV ]", 9); } else { printCentered("  135 FOV  ", 9); }
                if (iSelection == 7) { printCentered("[ Exit ]", 11); } else { printCentered("  Exit  ", 11); }

                int cols, rows;
                GetConsoleSize(cols, rows);

                printTo("Made by Zenn", 1, rows);

                break;
            }
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

            if ((GetAsyncKeyState(VK_SPACE) & 1) || (GetAsyncKeyState(VK_RETURN) & 1))
            {
                if (iPage == 0)
                {
                    switch(iSelection)
                    {
                        case 1:
                            iPage = 1;
                            iSelection = 1;

                            cout << "\033[2J\033[1;1H";
                            MenuHandler(iPage, iSelection);

                            break;
                        
                        case 3:
                            exit(0);

                            break;
                    }
                }
                else if (iPage == 1)
                {

                    switch(iSelection)
                    {
                        case 1:
                            IniEditor::WriteResolution("1080");
                            break;

                        case 2:
                            IniEditor::WriteResolution("910");
                            break;

                        case 3:
                            IniEditor::WriteResolution("760");
                            break;

                        case 4:
                            IniEditor::WriteResolution("630");
                            break;

                        case 5:
                            IniEditor::WriteResolution("520");
                            break;
                        
                        case 6:
                            IniEditor::WriteResolution("375");
                            break;
                        
                        case 7:
                            iPage = 0;
                            iSelection = 1;

                            cout << "\033[2J\033[1;1H";
                            MenuHandler(iPage, iSelection);
                            break;
                    }
                }
            }
        }
    }
}
// Includes //

#include <iostream>
#include <Windows.h>
#include "libs/menubase.h"

using namespace std;

// Variables //

int iPage = 0;
int iSelection = 1;

// Main //

int main()
{
    system("color");

    MenuBase::MenuHandler(iPage, iSelection);
}
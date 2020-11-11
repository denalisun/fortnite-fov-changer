#include <iostream>
#include <Windows.h>

using namespace std;

namespace IniEditor
{
    void WriteResolution(LPCSTR res)
    {
        WritePrivateProfileStringA("/Script/FortniteGame.FortGameUserSettings", "resolutionsizex", "1920", "C:\\Users\\Anthony Schofield\\AppData\\Local\\FortniteGame\\Saved\\Config\\WindowsClient\\GameUserSettings.ini");
        WritePrivateProfileStringA("/Script/FortniteGame.FortGameUserSettings", "resolutionsizey", res, "C:\\Users\\Anthony Schofield\\AppData\\Local\\FortniteGame\\Saved\\Config\\WindowsClient\\GameUserSettings.ini");
        WritePrivateProfileStringA("/Script/FortniteGame.FortGameUserSettings", "lastuserconfirmedresolutionsizex", "1920", "C:\\Users\\Anthony Schofield\\AppData\\Local\\FortniteGame\\Saved\\Config\\WindowsClient\\GameUserSettings.ini");
        WritePrivateProfileStringA("/Script/FortniteGame.FortGameUserSettings", "lastuserconfirmedresolutionsizey", res, "C:\\Users\\Anthony Schofield\\AppData\\Local\\FortniteGame\\Saved\\Config\\WindowsClient\\GameUserSettings.ini");
    }
}
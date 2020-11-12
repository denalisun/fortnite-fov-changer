#include <iostream>
#include <Windows.h>

using namespace std;

namespace IniEditor
{
    void WriteResolution(LPCSTR res, LPCSTR path)
    {   
        WritePrivateProfileStringA("/Script/FortniteGame.FortGameUserSettings", "resolutionsizex", "1920", path);
        WritePrivateProfileStringA("/Script/FortniteGame.FortGameUserSettings", "resolutionsizey", res, path);
        WritePrivateProfileStringA("/Script/FortniteGame.FortGameUserSettings", "lastuserconfirmedresolutionsizex", "1920", path);
        WritePrivateProfileStringA("/Script/FortniteGame.FortGameUserSettings", "lastuserconfirmedresolutionsizey", res, path);
    }
}
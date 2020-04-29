#include <bits/stdc++.h>
#include <Windows.h>
#include <locale>

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "");

    wifstream rl("rlist.txt");
    wifstream nl("nlist.txt");
    wifstream wl("wlist.txt");

    wcout << L"path : ";
    wchar_t path[512];
    wcin.getline(path, 512);

    int cnt = 0;
    while (!rl.eof())
    {
        int w;
        wl >> w;

        wchar_t name[512], rtmp[512];
        nl.getline(name, 512);
        if (name[wcslen(name) - 1] == L'\n') name[wcslen(name) - 1] = 0;
        if (name == L"") continue;
        rl.getline(rtmp, 512);
        if (rtmp[wcslen(rtmp) - 1] == L'\n') rtmp[wcslen(rtmp) - 1] = 0;
        wchar_t cmd[1024] = L"";
        wsprintfW(cmd, L"ffmpeg.exe -i \"%s\" -vcodec copy -acodec copy \"%s\\%d주차\\%s.mp4\"", rtmp, path, w, name);

        char ofn[512] = "";
        sprintf(ofn, "%d.bat", cnt++);
        wofstream of(ofn);
        of << cmd;
        of.close();
        system(("start " + string(ofn)).c_str());
    }
    
    rl.close();
    nl.close();
    wl.close();

    return 0;
}
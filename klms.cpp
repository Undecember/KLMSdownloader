#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "");

    wifstream rl("rlist.txt");
    wifstream nl("nlist.txt");
    wifstream wl("wlist.txt");

    wcout << L"path : ";
    wstring path;
    getline(wcin, path);

    int cnt = 0;
    while (!rl.eof())
    {
        int w;
        wl >> w;

        wstring name, rtmp;
        getline(nl, name);
        getline(rl, rtmp);
        wchar_t cmd[1024] = L"";
        wsprintfW(cmd, L"ffmpeg.exe -i \"%s\" -vcodec copy -acodec copy \"%s\\%d주차\\%s.mp4\"", rtmp.c_str(), path.c_str(), w, name.c_str());

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

    system("pause");
    return 0;
}
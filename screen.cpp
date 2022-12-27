#include <iostream>
#include <windows.h>
#include "functions.cpp"
#include "libraries/termcolor.hpp"

#include <io.h>
#include <fcntl.h>

using namespace std;

void vypis_listy(wstring x, wstring y, int row)
{
    for (int i = 0; i < 15; i++)
    {
        gotoxy(56+i, row);
        wcout << x;
    }

    gotoxy(71, row);
    wcout << y;

    for (int i = 0; i < 15; i++)
    {
        gotoxy(72 + i, row);
        wcout << x;
    }

    gotoxy(87, row);
    wcout << y;

    for (int i = 0; i < 15; i++)
    {
        gotoxy(88+i, row);
        wcout << x;
    }
}

void riadok(wstring start, wstring end, int row, wstring con)
{
    wstring lista = L"\x2550";

    gotoxy(55, row);
    wcout << start;
    vypis_listy(lista, con, row);
    gotoxy(103, row);
    wcout << end << endl;
}

void screen()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    wstring lista = L"\x2550";
    wstring pole = L"\x2551               \x2551               \x2551               \x2551";
    wstring krizik = L"\x256C"; // this
    wstring leftTop = L"\x2554";
    wstring rightTop = L"\x2557";
    wstring conMidStart = L"\x2560";
    wstring conMidEnd = L"\x2563";
    wstring conMidTop = L"\x2566"; // this
    wstring conMidBot = L"\x2569"; // this
    wstring leftBot = L"\x255A";
    wstring rightBot = L"\x255D";

    cout << termcolor::yellow << endl;

    riadok(leftTop, rightTop, 1, conMidTop);

    for (int i = 0; i < 4; i++)
    {
        gotoxy(55, 2+i);
        wcout << pole << endl;
    }

    riadok(conMidStart, conMidEnd, 6, krizik);

    gotoxy(55, 7);
    wcout << pole << endl;

    riadok(conMidStart, conMidEnd, 8, krizik);

    for (int i = 0; i < 4; i++)
    {
        gotoxy(55, 9+i);
        wcout << pole << endl;
    }

    riadok(leftBot, rightBot, 13, conMidBot);
    cout << termcolor::white << endl;
}

int main()
{
    system("cls");
    nastavenie_okna(1280, 720);
    screen();

    return 0;
}
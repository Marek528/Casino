#include <iostream>
#include <windows.h>
#include <functions.cpp>
#include <libraries/termcolor.hpp>

#include <io.h>
#include <fcntl.h>

using namespace std;

void vypis_listy(wstring x, int row)
{
    for (int i = 0; i < 50; i++)
    {
        gotoxy(53+i, row);
        wcout << x;
    }
}

void screen()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    wstring lista = L"\x2550";

    cout << termcolor::yellow << endl;
    gotoxy(52, 1);
    wcout << L"\x2554";
    vypis_listy(lista, 1);
    gotoxy(103, 1);
    wcout << L"\x2557" << endl;
    for (int i = 0; i < 12; i++)
    {
        gotoxy(52, 2+i);
        wcout << L"\x2551                                                  \x2551" << endl;
    }
    gotoxy(52, 14);
    wcout << L"\x255A";
    vypis_listy(lista, 14);
    gotoxy(103, 14);
    wcout << L"\x255D" << endl;
    cout << termcolor::white << endl;
}

int main()
{
    system("cls");
    nastavenie_okna(1280, 720);
    screen();

    return 0;
}
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
        gotoxy(56 + i, row);
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
        gotoxy(88 + i, row);
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

void vypis_obrazovky(wstring znaky[6], int cislo, int cislo1, int cislo2)
{
    srand(time(NULL));
    _setmode(_fileno(stdout), _O_U16TEXT);

    wstring lista = L"\x2550";
    wstring pole = L"\x2551               \x2551               \x2551               \x2551";
    wstring krizik = L"\x256C";
    wstring leftTop = L"\x2554";
    wstring rightTop = L"\x2557";
    wstring conMidStart = L"\x2560";
    wstring conMidEnd = L"\x2563";
    wstring conMidTop = L"\x2566";
    wstring conMidBot = L"\x2569";
    wstring leftBot = L"\x255A";
    wstring rightBot = L"\x255D";

    wstring riadok1[] = {L"\x2551       ", znaky[cislo], L"       \x2551       ", znaky[cislo1], L"       \x2551       ", znaky[cislo2], L"       \x2551"};
    wstring temporary1[7]; // dorobic !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    wstring riadok2[7];
    wstring temporary2[7]; // dorobic !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    wstring riadok3[7];

    cout << termcolor::yellow << endl;

    riadok(leftTop, rightTop, 1, conMidTop); // prvy riadok

    for (int i = 0; i < 3; i++)   // dalsie 3 riadky
    {
        gotoxy(55, 2 + i);
        wcout << pole << endl;
        if (i == 1)
        {
            gotoxy(55, 3);
            for (int j = 0; j < 7; j++) // druhy riadok sa vypisuju znaky
            {
                wcout << riadok1[j];
                if (j == 6)
                {
                    wcout << endl;
                }
            }
        }
    }

    riadok(conMidStart, conMidEnd, 5, krizik); // zaciatok stredovej ciary

    gotoxy(55, 6);
    for (int i = 0; i < 7; i++) // vyplnenie "vyhernych" znakov
    {
        riadok2[i] = riadok1[i];
    }
    for (int i = 0; i < 7; i++) // stredovy riadok so znakmi
    {
        wcout << riadok2[i];
        if (i == 6)
        {
            cout << endl;
        }
    }
    
    riadok(conMidStart, conMidEnd, 7, krizik); // koniec stredovej ciary

    for (int i = 0; i < 7; i++)
    {
        riadok3[i] = riadok2[i];   
    }
    for (int i = 0; i < 3; i++) // dalsie 3 riadky
    {
        gotoxy(55, 8 + i);
        wcout << pole << endl;
        if (i == 1)
        {
            gotoxy(55, 9);
            for (int j = 0; j < 7; j++) // druhy riadok sa vypisuju znaky
            {
                wcout << riadok3[j];
                if (j == 6)
                {
                    cout << endl;
                }
            }
        }
    }

    riadok(leftBot, rightBot, 11, conMidBot); // posledny riadok
    cout << termcolor::white << endl;
}

void screen(wstring znaky[6])
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    while (true)
    {
        int index = rand() % 6;
        int index2 = rand() % 6;
        int index3 = rand() % 6;
        vypis_obrazovky(znaky, index, index2, index3);
        Sleep(1000);
    }
}

int main()
{
    wstring arr[] = {L"@", L"#", L"$", L"%", L"&", L"*"};

    system("cls");
    nastavenie_okna(1280, 720);
    screen(arr);

    return 0;
}
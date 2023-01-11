#include <iostream>
#include <windows.h>
#include "functions.cpp"
#include "libraries/termcolor.hpp"
// zaznamenava input z klavesnice
#include <conio.h>

// kniznice na vypisanie specialnych znakov
#include <io.h>
#include <fcntl.h>

using namespace std;

wstring temp1[7], temp2[7], vyhernyRiadok[3];
int stavka;

void vypisListy(wstring x, wstring y, int row)
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
    vypisListy(lista, con, row);
    gotoxy(103, row);
    wcout << end << endl;
}

void podanieStavky(){
    while(true){
        gotoxy(0, 0);
        gotoxy(0, 13);
        SetConsoleOutputCP(1252);
        wcout << "kolko chces stavit? (" << (char)(128) << "): ";
        cin >> stavka;
        //vymaze riadok
        vymazRiadky();
        if (stavka > 0)
        {
            if(stavka <= peniaze)
            {
                peniaze -= stavka;
                gotoxy(0, 0);
                break;
            }
            else
            {
                wcout << "nemozes stavit viac ako mas!!" << endl;
                stavka = 0;
                continue;
            }
        }
        else
        {
            wcout << "nemozes stavit 0" << (char)(128) << " !!" << endl;
            stavka = 0;
            continue;
        }
    }
}

void vypisPrazdnejObrazovky()
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

    cout << termcolor::yellow << endl;

    riadok(leftTop, rightTop, 1, conMidTop); // prvy riadok

    for (int i = 0; i < 3; i++) // dalsie 3 riadky
    {
        gotoxy(55, 2 + i);
        wcout << pole << endl;
    }

    riadok(conMidStart, conMidEnd, 5, krizik); // zaciatok stredovej ciary

    gotoxy(55, 6);
    wcout << pole << endl;

    riadok(conMidStart, conMidEnd, 7, krizik); // koniec stredovej ciary

    for (int i = 0; i < 3; i++) // dalsie 3 riadky
    {
        gotoxy(55, 8 + i);
        wcout << pole << endl;
    }

    riadok(leftBot, rightBot, 11, conMidBot); // posledny riadok
    cout << termcolor::white << endl;
}

void vypisObrazovky(wstring znaky[22], int cislo, int cislo1, int cislo2)
{
    srand(time(NULL));
    // zmeni kodovanie konzoly na _O_U16TEXT
    _setmode(_fileno(stdout), _O_U16TEXT);

    // specialne znaky pre vytvorenie okna
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
    wstring riadok2[7];
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

    
    for (int i = 0; i < 7; i++) // vyplnenie "vyhernych" znakov
    {
        riadok2[i] = temp1[i];
    }
    gotoxy(55, 6);
    wcout << pole << endl;
    gotoxy(55, 6);
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
        riadok3[i] = temp2[i];
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

    for (int i = 0; i < 7; i++)
    {
        temp1[i] = riadok1[i];
        temp2[i] = riadok2[i];
    }

   vyhernyRiadok[0] = riadok2[1];
   vyhernyRiadok[1] = riadok2[3];
   vyhernyRiadok[2] = riadok2[5];
}
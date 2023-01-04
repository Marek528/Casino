#include <iostream>
#include <windows.h>
#include "functions.cpp"
#include "libraries/termcolor.hpp"
#include <conio.h>

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

void vymazRiadok(){
    wcout << "\r";
    wcout << "                                              ";
    wcout << "\r";
}

void vymazRiadky(){
    gotoxy(0, 12);
    for(int i = 0; i < 10; i++)
    {
        wcout << "                                                              " << endl;
    }
    gotoxy(0, 12);
}

void kontrolaVyhry(){ // dorobit !!!!!
    if(vyhernyRiadok[0] == vyhernyRiadok[1] && vyhernyRiadok[0] == vyhernyRiadok[2])
    {
        peniaze += (stavka * 2); 
        gotoxy(80, 12);
        wcout << "vyhral si!!" << endl;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        wcout << "na ucet sa ti pripisalo " << (stavka*2) << "eur";
    }
}

void podanieStavky(){
    while(true){
        wcout << "kolko chces stavit?: ";
        cin >> stavka;
        //vymaze riadok
        vymazRiadky();
        if(stavka <= peniaze)
        {
            peniaze -= stavka;
            break;
        }
        else
        {
            wcout << "nemozes stavit viac ako mas!!" << endl;
            stavka = 0;
            continue;
        }
    }
}

void vypisObrazovky(wstring znaky[9], int cislo, int cislo1, int cislo2)
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

void screen(wstring znaky[9])
{
    int counter = 0;
    _setmode(_fileno(stdout), _O_U16TEXT);

    podanieStavky();
    system("cls");

    while (true)
    {
        gotoxy(18, 4);
        cout << termcolor::blue << endl;
        wcout << "Tvoj aktualny balans: " << peniaze;
        gotoxy(24, 6);
        wcout << "Stavil si: " << stavka;
        cout << termcolor::white << endl;
        int index = rand() % 9;
        int index2 = rand() % 9;
        int index3 = rand() % 9;
        vypisObrazovky(znaky, index, index2, index3);
        Sleep(600);

        if (counter > 5)
        {
            Sleep(700);
            if (counter > 7)
            {
                Sleep(750);
                if (counter == 9)
                {
                    // opyta sa ci chces tocit odznova
                    wcout << "chces tocit znova? ENTER: ano, BACKSPACE: nie";
                    int znova = getch();
                    vymazRiadok();
                    if(znova == 13){
                        stavka = 0;
                        podanieStavky();
                        counter = 0;
                        continue;
                    }
                    else if(znova == 127 || znova == 8){
                        break;
                    }
                }
            }
        }

        counter++;

    }

}

/*int main()
{
    wstring arr[] = {L"@", L"#", L"$", L"%", L"&", L"*", L"+", L"^", L"?"};

    system("cls");
    nastavenie_okna(1280, 720);
    screen(arr);
    

    return 0;
}*/
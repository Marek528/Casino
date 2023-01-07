#include <iostream>
#include "welcome.cpp"
#include "screen.cpp"

wstring arr[] = {L"@", L"?", L"#", L"+", L"*", L"$", L"@", L"@", L"@", L"@", L"?", L"?", L"?", L"?", L"#", L"#", L"#", L"+", L"+", L"+", L"*", L"*"};

void vypisPenazi()
{
    gotoxy(18, 4);
    cout << termcolor::blue << endl;
    // riadok 12 az 22 zapezbecuje vymazanie predoslej stavky a vkladu aby sa po novom zatoceni neprekryvali hodnoty
    wcout << "Tvoj aktualny zostatok: ";
    gotoxy(42, 4);
    wcout << "             ";
    gotoxy(42, 4);
    wcout << peniaze;
    gotoxy(24, 6);
    wcout << "Stavil si: ";
    gotoxy(35, 6);
    wcout << "                    ";
    gotoxy(35, 6);
    wcout << stavka;
    cout << termcolor::white << endl;
}

void vypisVyhry(int nasobitel)
{
    peniaze += (stavka * nasobitel);
    gotoxy(74, 12);
    wcout << "VYHRAL SI !!" << endl;
    gotoxy(66, 14);
    wcout << "Na ucet sa ti pripisalo " << (stavka * nasobitel) << " eur" << endl;
}

void kontrolaVyhry()
{
    if (vyhernyRiadok[0] == arr[0] && vyhernyRiadok[1] == arr[0] && vyhernyRiadok[2] == arr[0])
        vypisVyhry(2);

    else if (vyhernyRiadok[0] == arr[1] && vyhernyRiadok[1] == arr[1] && vyhernyRiadok[2] == arr[1])
        vypisVyhry(2);

    else if (vyhernyRiadok[0] == arr[2] && vyhernyRiadok[1] == arr[2] && vyhernyRiadok[2] == arr[2])
        vypisVyhry(3);

    else if (vyhernyRiadok[0] == arr[3] && vyhernyRiadok[1] == arr[3] && vyhernyRiadok[2] == arr[3])
        vypisVyhry(3);

    else if (vyhernyRiadok[0] == arr[4] && vyhernyRiadok[1] == arr[4] && vyhernyRiadok[2] == arr[4])
        vypisVyhry(4);

    else if (vyhernyRiadok[0] == arr[5] && vyhernyRiadok[1] == arr[5] && vyhernyRiadok[2] == arr[5])
        vypisVyhry(10);
}

void screen(wstring znaky[22])
{
    int counter = 0;
    _setmode(_fileno(stdout), _O_U16TEXT);

    vypisPrazdnejObrazovky();
    podanieStavky();
    system("cls");

    while (true)
    {

        bool mamPokracovat;

        vypisPenazi();

        gotoxy(74, 12);
        wcout << "            ";
        gotoxy(66, 14);
        wcout << "                             ";

        // vysvetlivky pre vyherne znaky
        cout << termcolor::red;
        gotoxy(116, 3);
        wcout << "@ x 2";
        gotoxy(116, 4);
        wcout << "? x 2";
        gotoxy(116, 5);
        wcout << "# x 3";
        gotoxy(116, 6);
        wcout << "+ x 3";
        gotoxy(116, 7);
        wcout << "* x 4";
        gotoxy(116, 8);
        wcout << "$ x 10";

        int index = rand() % 22;
        int index2 = rand() % 22;
        int index3 = rand() % 22;
        
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
                    kontrolaVyhry();
                    vypisPenazi();
                    // opyta sa ci chces tocit odznova
                    gotoxy(0, 13);
                    
                    while(true)
                    {
                        wcout << "chces tocit znova? ENTER: ano, BACKSPACE: nie";
                        int znova = getch();
                        vymazRiadok();
                        //kontroluje enter
                        if (znova == 13)
                        {
                            stavka = 0;
                            podanieStavky();
                            counter = 0;
                            mamPokracovat = true;
                            break;
                        }
                        //kontroluje backspace
                        else if (znova == 127 || znova == 8)
                        {
                            mamPokracovat = false;
                            break;
                        }
                        else
                        {
                            wcout << "ENTER alebo BACKSPACE" << endl;
                            continue;
                        }
                    }
                    if(mamPokracovat)
                    {
                        continue;
                    }
                    else if(mamPokracovat == false)
                    {
                        break;
                    }
                }
            }
        }

        counter++;
    }
}

int main(void){
    nastavenieOkna(1280, 720);

    system("cls");

    welcome();
    SetConsoleOutputCP(1252);
    while(true)
    {
        cout << "tvoj vklad (" << (char)(128) << "): ";
        cin >> peniaze;
        if(peniaze <= 1000000 && peniaze > 0)
        {
            break;
        }
        else
        {
            peniaze = 0;
            cout << "Mozes vlozit od 1 po 1 000 000 " << (char)(128)  << endl;
            continue;
        }
    }

    system("cls");
    
    screen(arr);
    
}
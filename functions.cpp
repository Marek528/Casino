#include <windows.h>
#include <io.h>
#include <fcntl.h>

int peniaze;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void nastavenieOkna(int x, int y)
{
    // kontrola nad konzolou
    HWND konzola = GetForegroundWindow();
    
    // kontrola obrazovky
    HWND hwndScreen;
    RECT rectScreen;
    hwndScreen = GetDesktopWindow();
    GetWindowRect(hwndScreen, &rectScreen);

    // nastavenie vysky a dlzky okna a zabezpecenie aby sa nedalo zväcsit
    MoveWindow(konzola, rectScreen.left, rectScreen.top, x, y, TRUE);
    SetWindowLong(konzola, GWL_STYLE, GetWindowLong(konzola, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    // zisti aktualnu vysku a dlzku konzoly
    RECT rConsole;
    GetWindowRect(konzola, &rConsole);
    int Width = rConsole.left = rConsole.right;
    int Height = rConsole.bottom - rConsole.top;

    // vycentruje konzolu do stredu obrazovky
    int ConsolePosX;
    int ConsolePosY;
    ConsolePosX = ((rectScreen.right - rectScreen.left) / 2 - Width / 2);
    ConsolePosY = ((rectScreen.bottom - rectScreen.top) / 2 - Height / 2);
    SetWindowPos(konzola, NULL, ConsolePosX, ConsolePosY, Width, Height, SWP_SHOWWINDOW || SWP_NOSIZE);
}

void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void vymazRiadok()
{
    wcout << "\r";
    wcout << "                                              ";
    wcout << "\r";
}

void vymazRiadky()
{
    gotoxy(0, 12);
    for (int i = 0; i < 24; i++)
    {
        wcout << "                                                              " << endl;
    }
    gotoxy(0, 12);
}

void kontrolaPenazi()
{
    while (peniaze == 0)
    {
        wcout << "Dosli ti peniaze. Tvoj novy vklad: ";
        cin >> peniaze;
        if (peniaze <= 0)
        {
            peniaze = 0;
            SetConsoleOutputCP(1252);
            wcout << "Musis vlozit viac ako 0" << (char)(128) << " !" << endl;
            continue;
        }
        else
        {
            vymazRiadky();
            break;
        }
    }
}
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
#include <windows.h>

int peniaze;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void nastavenieOkna(int x, int y)
{
    HWND konzola = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(konzola, &ConsoleRect);

    MoveWindow(konzola, ConsoleRect.left, ConsoleRect.top, x, y, TRUE);
}

void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
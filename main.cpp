#include <iostream>
#include "welcome.cpp"
#include "screen.cpp"



int main(void){
    wstring arr[] = {L"@", L"#"/*, L"$", L"%", L"&", L"*", L"+", L"^", L"?"*/};

    system("cls");

    welcome();
    cout << "tvoj vklad: ";
    cin >> peniaze;

    system("cls");
    
    screen(arr);
    
}
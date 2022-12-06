#include <iostream>
#include <windows.h>

//externa kniznica
#include "Libraries/termcolor.hpp"


using namespace std;


int peniaze;
string kod;



//toto vypise medzery
void medzery(int medzier){

    char medzera = ' ';

    for (int i = 0; i <= medzier; i++){
        cout << medzera;
    }
}

//toto vypise uvitaciu spravu
void welcome(){


    HWND konzola = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(konzola, &ConsoleRect);

    MoveWindow(konzola, ConsoleRect.left, ConsoleRect.top, 1280, 720, TRUE);

    string gold[] =    { "    # # #         # # #       #        # # #    ",
                         "   #            #       #     #        #     #  ",
                         " #            #           #   #        #       #",
                         " #    # # #   #           #   #        #       #",
                         " #        #   #           #   #        #       #",
                         "   #      #     #       #     #        #     #  ",
                         "     # # #        # # #       # # # #  # # #    "};
    
    string casino[] = {"    # # #         #          # # # #  #  #       #       # # #    ",
                       "  #              # #       #          #  # #     #     #       #   ",
                       " #              #   #      #          #  #  #    #   #           #",
                       " #             #     #       # # #    #  #   #   #   #           #",
                       " #            # # # # #            #  #  #    #  #   #           #",
                       "   #         #         #           #  #  #     # #     #       #  ",
                       "     # # #  #           #  # # # #    #  #       #       # # #    "};

    //vypise "fruit" zhora dole
    for (int i = 0; i < 7; i++){
        medzery(53);
        cout << termcolor::yellow << gold[i] << endl;
        Sleep(150);
    }

    //urobi medzery medzi slovami
    cout << endl << endl;         
    
    //vypise "casino" zhora dole
    for (int i = 0; i < 7; i++){
        medzery(44);
        cout << termcolor::yellow << casino[i] << endl;
        Sleep(150);
    }
    cout << termcolor::white << "Tvoj vklad (EUR): ";
    cin >> peniaze;
    system("cls");
}




int main(void){
    welcome();
}
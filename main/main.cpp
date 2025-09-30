#include <iostream>
#include <ncurses.h>
#include <Menu.h>

using namespace std;

int main() {
    initscr();              
    noecho();              
    cbreak();              
    keypad(stdscr, TRUE);  

    initializeColors();     

    while (true) {
        displayMainMenu();  
        
        int choice = getch() - '0';  
        
        switch (choice) {
            case 1:  
                login();
                break;
            case 2: 
                registerUser();
                break;
            case 3:  
                endwin();  
                return 0;
            default:
                printw("Opción no válida. Presiona cualquier tecla para continuar.");
                getch();
        }
    }

    endwin(); 
    return 0;
}
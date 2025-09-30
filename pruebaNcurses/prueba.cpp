#include <iostream>
#include <string>
#include <ncurses.h>
using namespace std;

int main(){
    initscr();
    keypad(stdscr, TRUE);

    
    printw("presione lo que quiera: ");
    refresh();
    int ch = getch();

    printw("\nhas seleccionado esta tecla: %c\n", ch);
    refresh();
    printw("precione cualqueir tecla para salir...");
    refresh();
    getch();


    endwin();


    return 0;


}
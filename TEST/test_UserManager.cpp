#include <UserManager.h>
#include <ncurses.h>

int main() {
    initscr(); 
    
    UserManager userManager;
    userManager.loadFromFile("students.dat");
    userManager.showUserInfo("johndoe@example.com");

    refresh();
    getch(); 
    endwin(); 
    return 0;
}
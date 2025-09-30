#include <vector>
#include <Student.h>
#include <ncurses.h>

using namespace std;

int main() {
    initscr();
    Student student("John Doe", 1);
    
    Grade grade1("Math", 95);
    Grade grade2("Sports", 97);
    Grade grade3("Art", 99);

    student.addGrade(grade1);
    student.addGrade(grade2);
    student.addGrade(grade3);
    
    auto v = student.getGrades();

    for (auto g : v)
    {
        cout << g.subject << ": " << g.score << endl;
    }

    refresh();
    getch(); 
    endwin(); 
    return 0;
}
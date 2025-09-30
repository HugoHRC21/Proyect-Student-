#include <Teacher.h>
#include <ncurses.h>

using namespace std;

int main() {
    
    Teacher Teacher1("Jane Smith", 1, "jane@example.com", "password123");
    Teacher1.showInformation();

    Student student("John Doe", 2);
    Grade grade("Math", 90);
    Teacher1.assignGrade(student, grade);

    auto grades = student.getGrades(); 


    for (auto g : grades)
        cout << g.subject << ": " << g.score << endl; 
    return 0;
}
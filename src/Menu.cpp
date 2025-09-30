#include <ncurses.h>
#include <vector>
#include <Menu.h>
#include <FileHandling.h>

using namespace std;

void initializeColors() {
    start_color();  // Inicializa el uso de colores
    init_pair(1, COLOR_WHITE, COLOR_BLUE);  // Opción normal
    init_pair(2, COLOR_BLACK, COLOR_YELLOW); // Opción resaltada
}

void displayMainMenu() {
    clear();
    printw("Bienvenido al Sistema de Gestión de Notas\n");

    const char* options[] = {
        "Iniciar Sesión",
        "Registrar Usuario",
        "Salir"
    };
    int numOptions = sizeof(options) / sizeof(options[0]);
    int selected = 0;  // Opción seleccionada

    while (true) {
        for (int i = 0; i < numOptions; ++i) {
            if (i == selected) {
                attron(COLOR_PAIR(2)); // Resaltado
            }
            printw("%s\n", options[i]);
            if (i == selected) {
                attroff(COLOR_PAIR(2)); // Apaga el resaltado
            }
        }
        
        int ch = getch();
        if (ch == KEY_UP) {
            selected = (selected - 1 + numOptions) % numOptions;
        } else if (ch == KEY_DOWN) {
            selected = (selected + 1) % numOptions;
        } else if (ch == '\n') { // Enter
            break; // Sal de la selección
        }
        
        clear(); // Limpia la pantalla antes de volver a imprimir
    }

    // Maneja la opción seleccionada
    switch (selected) {
        case 0:
            login();
            break;
        case 1:
            registerUser();
            break;
        case 2:
            endwin();  // Finaliza ncurses
            exit(0);
    }
}

void login() {
    clear();
    printw("Iniciar Sesión\n");
    printw("ID: ");
    int id;
    scanw("%d", &id);  // Lee el ID

    vector<Teacher> teachers;
    loadTeachers(teachers);
    for ( auto& teacher: teachers) {
        if (teacher.getId() == id) {
            printw("Bienvenido, %s\n", teacher.getName().c_str());
            assignGrade();
            return;
        }
    }

    vector<Student> students;
    loadStudents(students);
    for ( auto& student : students) {
        if (student.getId() == id) {
            printw("Bienvenido, %s\n", student.getName().c_str());
            viewGrades();
            return;
        }
    }

    printw("ID no válido. Presiona cualquier tecla para continuar.");
    getch();
}

void registerUser() {
    clear();
    printw("Registrar Usuario\n");
    printw("1. Registrar Profesor\n");
    printw("2. Registrar Estudiante\n");
    printw("Seleccione una opción: ");
    
    int choice = getch() - '0';  // Lee la opción del usuario
    
    if (choice == 1) {
        string name;
        int id;
        printw("Nombre: ");
        echo();
        getstr(&name[0]);  // Lee el nombre
        printw("ID: ");
        scanw("%d", &id);  // Lee el ID
        Teacher teacher(name, id);
        saveTeacher(teacher);
        printw("Profesor registrado. Presiona cualquier tecla para continuar.");
    } else if (choice == 2) {
        string name;
        int id;
        printw("Nombre: ");
        echo();
        getstr(&name[0]);  // Lee el nombre
        printw("ID: ");
        scanw("%d", &id);  // Lee el ID
        Student student(name, id);
        saveStudent(student);
        printw("Estudiante registrado. Presiona cualquier tecla para continuar.");
    } else {
        printw("Opción no válida. Presiona cualquier tecla para continuar.");
    }
    getch();
    noecho();
}


void assignGrade(vector<Student>& students) {
    string studentName;
    int grade;

    clear(); 
    printw("Asignar Calificación\n");
    printw("Nombre del Estudiante: ");
    char name[50];
    getstr(name); // Lee el nombre del estudiante

    printw("Calificación: ");
    scanw("%d", &grade); // Lee la calificación

    // Busca al estudiante
    for (auto& student : students) {
        if (student.getName() == string(name)) {
            student.setGrade(grade); 
            printw("Calificación asignada a %s: %d\n", student.getName().c_str(), grade);
            break;
        }
    }
    printw("Presiona cualquier tecla para continuar...");
    getch(); 
}



void viewGrades(vector<Student>& students) {
    clear(); 
    printw("Ver Calificaciones\n");

    for (const auto& student : students) {
        printw("Estudiante: %s, Calificación: %d\n", student.getName().c_str(), student.getGrade());
    }

    printw("Presiona cualquier tecla para continuar...");
    getch(); 
}
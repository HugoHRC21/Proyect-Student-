# Variables
CC = g++
CFLAGS = -c -Iinclude # Añadir -I para incluir la carpeta 'include'
CLIBS = -lncurses
SOURCES = main/main.cpp src/Person.cpp src/Teacher.cpp src/Student.cpp src/Grade.cpp src/FileHandling.cpp src/Menu.cpp
OBJECTS = $(patsubst main/%.cpp, obj/main/%.o, $(patsubst src/%.cpp, obj/src/%.o, $(SOURCES)))
EXECUTABLE = bin/main.exe

# Regla principal
all: $(EXECUTABLE)

# Cómo enlazar los archivos .o para crear el ejecutable
$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(CLIBS)

# Cómo compilar los archivos .cpp a .o en los directorios obj/main y obj/src
obj/main/%.o: main/%.cpp
	mkdir -p obj/main
	$(CC) $(CFLAGS) $< -o $@ $(CLIBS)

obj/src/%.o: src/%.cpp
	mkdir -p obj/src
	$(CC) $(CFLAGS) $< -o $@ $(CLIBS)

# Limpiar los archivos generados
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
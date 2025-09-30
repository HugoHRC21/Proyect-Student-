#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <Teacher.h>
#include <Student.h>
#include <vector>

void saveTeacher(const Teacher& teacher);
void loadTeachers(vector<Teacher>& teachers);
void saveStudent(const Student& student);
void loadStudents(vector<Student>& students);

#endif // 
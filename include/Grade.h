#ifndef GRADE_H
#define GRADE_H

#include <string>

using namespace std;

class Grade {
public:
    string subject;
    float score;

    Grade(const string& subject, float score) : subject(subject), score(score) {}
};


#endif
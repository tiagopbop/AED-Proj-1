#ifndef REMAKE_STUDENT_H
#define REMAKE_STUDENT_H
#include <string>
using namespace std;

class Student {
private:
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;

public:
    //                                           Getters

    string getStudentCode();
    string getStudentName();
    string getUcCode();
    string getClassCode();

    //                                           Setters

    void setUcCode(string code);
    void setClassCode(string code);
    void setStudentName(string sn);
    void setStudentCode(string sc);
};


#endif //REMAKE_STUDENT_H

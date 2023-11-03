#include "Student.h"


string Student::getStudentCode() {
    return StudentCode;
}
string Student::getStudentName() {
    return StudentName;
}
string Student::getUcCode() {
    return UcCode;
}
string Student::getClassCode() {
    return ClassCode;
}

//                                           Setters

void Student::setUcCode(string code) {
    this->UcCode = code;
}
void Student::setClassCode(string code) {
    this->ClassCode = code;
}
void Student::setStudentName(string sn) {
    this->StudentName=sn;
}
void Student::setStudentCode(string sc) {
    this->StudentCode=sc;
}

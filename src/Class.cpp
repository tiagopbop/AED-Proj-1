#include "Class.h"
using namespace std;

//                                         Getters

string Class::get_ClassCode() {
    return ClassCode;
}
string Class::get_UcCode() {
    return UcCode;
}
string Class::get_Weekday() {
    return Weekday;
}
float Class::get_StartHour() {
    return StartHour;
}
float Class::get_Duration() {
    return Duration;
}
string Class::get_type() {
    return Type;
}

//                                         Setters

void Class::set_ClassCode(string cc) {
    this->ClassCode=cc;
}
void Class::set_UcCode(string uc) {
    this->UcCode = uc;
}
void Class::set_Weekday(string wd) {
    this->Weekday = wd;
}
void Class::set_StartHour(float sh) {
    this->StartHour = sh;
}
void Class::set_Duration(float dr) {
    this->Duration= dr;
}
string Class::set_type(string ty) {
    this->Type = ty;
}

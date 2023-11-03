#include "Course.h"
//                                        Getters

        string Course::get_UcCode() {
    return UcCode;
}
string Course::get_ClassCode() {
    return ClassCode;
}

//                                        Setters

void Course::set_UcCode(string uc) {
    this->UcCode = uc;
}
void Course::set_ClassCode(string clas) {
    this->UcCode = clas;
}
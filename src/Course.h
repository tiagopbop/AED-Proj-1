#ifndef REMAKE_COURSE_H
#define REMAKE_COURSE_H

#include <string>
using namespace std;

class Course {
private:
    string UcCode;
    string ClassCode;

public:
    //                                        Getters

    string get_UcCode();
    string get_ClassCode();

    //                                        Setters

    void set_UcCode(string uc);
    void set_ClassCode(string clas);
};


#endif //REMAKE_COURSE_H

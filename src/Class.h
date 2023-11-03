#ifndef REMAKE_CLASS_H
#define REMAKE_CLASS_H

#include <string>
using namespace std;
class Class {
    private:
        string ClassCode;
        string UcCode;
        string Weekday;
        float StartHour;
        float Duration;
        string Type;

    public:
    //                                         Getters

        string get_ClassCode();
        string get_UcCode();
        string get_Weekday();
        float get_StartHour();
        float get_Duration();
        string get_type();

    //                                         Setters

        void set_ClassCode(string cc);
        void set_UcCode(string uc);
        void set_Weekday(string wd);
        void set_StartHour(float sh);
        void set_Duration(float dr);
        string set_type(string ty);
};


#endif //REMAKE_CLASS_H

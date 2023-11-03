#ifndef REMAKE_SCHEDULES_CHECKER_H
#define REMAKE_SCHEDULES_CHECKER_H


#include <string>

using namespace std;

class Schedules_Checker {
private:
    int a;

public:
    static void check_schedule_student(string id);

    static void print_schedule_student(string uc, string cc);

    static void check_schedule_class(string in);
};


#endif //REMAKE_SCHEDULES_CHECKER_H

#ifndef REMAKE_SCHEDULES_CHECKER_H
#define REMAKE_SCHEDULES_CHECKER_H


#include <string>

using namespace std;

class Schedules_Checker {

public:
    static void check_schedule_student(const string& id);

    static void print_schedule_student(const string& uc, const string& cc);

    static void check_schedule_class(const string& in);
};


#endif //REMAKE_SCHEDULES_CHECKER_H

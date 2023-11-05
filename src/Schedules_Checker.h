#ifndef REMAKE_SCHEDULES_CHECKER_H
#define REMAKE_SCHEDULES_CHECKER_H


#include <string>

using namespace std;

class Schedules_Checker {

public:
    static void check_schedule_student(const string& id);

    /**
    * @brief Print the class schedule for a specific university class (UC) and class code (CC).
    *
    * @param uc The code of the university class (UC) for which the schedule is to be printed.
    * @param cc The class code (CC) for which the schedule is to be printed.
    *
    * This function reads class schedule data from the "classes.csv" file and prints the schedule for the specified
    * university class (UC) and class code (CC). The schedule includes class information such as class name, time,
    * duration, and type.
    */
    static void print_schedule_student(const string& uc, const string& cc);

    static void check_schedule_class(const string& in);
};


#endif //REMAKE_SCHEDULES_CHECKER_H

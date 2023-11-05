#ifndef REMAKE_LISTSTUDENTS_H
#define REMAKE_LISTSTUDENTS_H


#include <string>

using namespace std;

class ListStudents {
public:

    /**
    * @brief Lists students in a specific class of a University Class (UC).
    *
    * @param uc The code of the UC.
    * @param cc The code of the class within the UC.
    *
    * This function reads data from a CSV file containing student-class registrations and lists students who are
    * registered in a specific class of a given University Class (UC). The function identifies students in the specified
    * UC and class and displays their names and student codes.
    */
    static void check_class_students(const string& uc, const string& cc);

    static void check_UC_students(const string& id);

    static void check_year_students(const string& id);
};


#endif //REMAKE_LISTSTUDENTS_H

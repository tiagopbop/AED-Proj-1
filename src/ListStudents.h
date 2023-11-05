#ifndef REMAKE_LISTSTUDENTS_H
#define REMAKE_LISTSTUDENTS_H


#include <string>

using namespace std;

class ListStudents {
public:
    static void check_class_students(const string& uc, const string& cc);

    static void check_UC_students(const string& id);

    static void check_year_students(const string& id);
};


#endif //REMAKE_LISTSTUDENTS_H

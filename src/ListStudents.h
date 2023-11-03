#ifndef REMAKE_LISTSTUDENTS_H
#define REMAKE_LISTSTUDENTS_H


#include <string>

using namespace std;

class ListStudents {
public:
    static void check_class_students(string uc, string cc);

    static void check_UC_students(string id);

    static void check_year_students(string id);
};


#endif //REMAKE_LISTSTUDENTS_H

#ifndef REMAKE_LISTSTUDENTS_H
#define REMAKE_LISTSTUDENTS_H


#include <string>

using namespace std;

class ListStudents {
public:
    static void check_class_students(std::__cxx11::basic_string<char> id);

    static void check_UC_students(std::string id);

    static void check_year_students(std::string id);
};


#endif //REMAKE_LISTSTUDENTS_H

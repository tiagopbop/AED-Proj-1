#ifndef REMAKE_OCUPATION_H
#define REMAKE_OCUPATION_H
#include <string>
using namespace std;

class Ocupation {
public:
    static void most_students(string in);

    static int check_class_occupation_per_uc(string id, string uc);

    static void check_class_occupation(string id);

    static void check_students_by_UCs(string in);

    static void check_UC_occupation(string id);

    static void check_year_occupation(string id);

    static void greatest_number(string id);
};


#endif //REMAKE_OCUPATION_H

#ifndef REMAKE_OCUPATION_H
#define REMAKE_OCUPATION_H


#include <string>

using namespace std;

class Ocupation {
public:
    static void most_students(const string& in);

    static int check_class_occupation_per_uc(const string& id, const string& uc);

    static void check_class_occupation(const string& id,const string& uc);

    static void check_students_by_UCs(const string& in);

    static void check_UC_occupation(const string& id);

    static void check_year_occupation(const string& id);

    static void greatest_number(const string& id);
};


#endif //REMAKE_OCUPATION_H

#ifndef REMAKE_OCUPATION_H
#define REMAKE_OCUPATION_H


#include <string>

using namespace std;

class Ocupation {
public:
    static void most_students(const string& in);

    /**
    * @brief Check the occupation of a specific class within a university class (UC).
    *
    * @param id The unique identifier of the class to be checked.
    * @param uc The university class (UC) to which the class belongs.
    *
    * This function reads the enrollment data from the "students_classes.csv" file and counts the number of students
    * enrolled in a specific class within a given university class (UC).
    */
    static int check_class_occupation_per_uc(const string& id, const string& uc);

    static void check_class_occupation(const string& id,const string& uc);

    /**
     * @brief Checks the number of students registered in at least a certain number of University Classes (UCs).
     *
     * @param in The minimum number of UCs a student must be registered in to be counted.
     *
     * This function reads data from a CSV file containing student-class registrations and counts the number of students
     * who are registered in at least a certain number of UCs. The minimum required UC count is specified by the 'in' parameter.
     */
    static void check_students_by_UCs(const string& in);

    static void check_UC_occupation(const string& id);

    static void check_year_occupation(const string& id);

    /**
    * @brief Find and display the classes with the highest number of students enrolled.
    *
    * @param id The number of classes with the highest enrollment to display.
    *
    * This function reads enrollment data from the "students_classes.csv" file and identifies the classes with the
    * highest number of students enrolled. It then displays the specified number of classes with the highest enrollment.
    */
    static void greatest_number(const string& id);
};


#endif //REMAKE_OCUPATION_H

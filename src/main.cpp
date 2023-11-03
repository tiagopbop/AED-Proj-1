#include <iostream>
#include "Student.h"
#include "Class.h"
#include "Course.h"
#include "Changes.h"
#include "Schedules_Checker.h"
#include "Ocupation.h"
#include "Schedules_Checker.h"
#include "ListStudents.h"

using namespace std;

int main() {

    cout << endl;
    cout << "Please choose a number for the desired functionality:" << endl;
    cout << '1' << ": Check student schedule" << endl;
    cout << '2' << ": Check class schedule" << endl;
    cout << '3' << ": Check students of a given class, UC or year" << endl;
    cout << '4' << ": Check number of students in a given minimum number of UCs" << endl;
    cout << '5' << ": Check occupation of a given class, UC or year" << endl;
    cout << '6' << ": Check the UCs with greatest number of students" << endl;
    cout << '7' << ": Check the classes with the greatest number of students" << endl;
    cout << "8" << ": Make changes" << endl;
    cout << '0' << ": Quit" << endl;
    cout << endl;

    cout << "Decision: ";
    int decision;
    cin >> decision;
    cout << endl;

    string id1;
    string uc1;
    string cl1;
    string uc2;



    string in;

    while (true) {

        switch (decision) {
            case 1:

                cout << "Which student id: ";
                cin >> in;
                Schedules_Checker::check_schedule_student(in);
                break;

            case 2:

                cout << "Which class: ";
                cin >> in;
                Schedules_Checker::check_schedule_class(in);
                break;

            case 3:

                cout << "Do you want to check a class, UC or year: ";
                cin >> in;

                if (in == "class") {

                    cout << "Which class: ";
                    cin >> in;
                    ListStudents::check_class_students(in);

                }
                else if (in == "UC") {

                    cout << "Which UC: ";
                    cin >> in;
                    ListStudents::check_UC_students(in);

                }
                else {

                    cout << "Which year: ";
                    cin >> in;
                    ListStudents::check_year_students(in);

                }
                break;

            case 4:

                cout << "In how many UCs do you want to check for: ";
                cin >> in;
                Ocupation::check_students_by_UCs(in);
                break;

            case 5:

                cout << "Do you want to check the occupation of a class, UC or year: ";
                cin >> in;

                if (in == "class") {

                    cout << "Which class: ";
                    cin >> in;
                    Ocupation::check_class_occupation(in);

                }
                else if (in == "UC") {

                    cout << "Which UC: ";
                    cin >> in;
                    Ocupation::check_UC_occupation(in);

                }
                else {

                    cout << "Which year: ";
                    cin >> in;
                    Ocupation::check_year_occupation(in);

                }
                break;

            case 6:

                cout << "How many UCs would you like to be be presented with: ";
                cin >> in;
                Ocupation::greatest_number(in);
                break;

            case 7:

                cout << "How many classes would you like to be be presented with: ";
                cin >> in;
                Ocupation::most_students(in);
                break;

            case 8:

                cout << "1: Join UC " <<endl;
                cout << "2: Leave UC " <<endl;
                cout << "3: Swap UC " << endl;
                cout << "4: Swap class " << endl;
                cout << "5: Execute 4/3 -> 2/1 -> 7/6 " << endl;
                cout << endl;
                cout << "Decision: ";

                int dec;
                cin >> dec;
                cout << endl;

                switch (dec) {
                    case 1:
                        cout << "Student ID: ";
                        cin >> id1;
                        cout << endl << "UC to join: ";
                        cin >> uc1;
                        cout << endl;
                        Changes::call_joinuc(id1, uc1);
                        break;

                    case 2:
                        cout << "Student ID: ";
                        cin >> id1;
                        cout << endl << "UC to leave: ";
                        cin >> uc1;
                        Changes::call_leaveuc(id1, uc1);
                        break;
                    case 3:
                        cout << "Student ID: ";
                        cin >> id1;
                        cout << endl << "UC to leave: ";
                        cin >> uc1;
                        cout << endl << "UC to join: ";
                        cin >> uc2;
                        cout << endl << "Class to join: ";
                        cin >> cl1;
                        Changes::call_swapuc(id1, uc1, uc2, cl1);
                        break;

                    case 4:

                        cout << "Student ID: ";
                        cin >> id1;
                        cout << endl << "Desired UC: ";
                        cin >> uc1;
                        cout << endl << "Class to join: ";
                        cin >> cl1;
                        Changes::call_swapclass(id1, uc1, cl1);
                        break;

                        /*case 5:

                            Changes::call_multi(id1,id2,id3);
                            break;*/
                    default:
                        break;
                }
                break;

            case 0:

                cout << endl;
                cerr << "Program closed" << endl;
                return 0;
        }

        cout << endl;
        cout << "Wish to do anything else?" << endl;
        cout << '1' << ": Check student schedule" << endl;
        cout << '2' << ": Check class schedule" << endl;
        cout << '3' << ": Check students of a given class, UC or year" << endl;
        cout << '4' << ": Check number of students in a given minimum number of UCs" << endl;
        cout << '5' << ": Check occupation of a given class, UC or year" << endl;
        cout << '6' << ": Check the UCs with greatest number of students" << endl;
        cout << '7' << ": Check the classes with the greatest number of students" << endl;
        cout << "8" << ": Make changes" << endl;
        cout << '0' << ": Quit" << endl;
        cout << endl;

        cout << "Decision: ";
        cin >> decision;
    }
}

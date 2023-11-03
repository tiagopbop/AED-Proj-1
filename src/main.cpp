#include <iostream>
#include "Student.h"
#include "Changes.h"
#include "Schedules_Checker.h"
#include "Ocupation.h"
#include "ListStudents.h"

using namespace std;

int main() {

    int cap;

    cout << endl;
    cout << "\033[1;34mPlease define a maximum capacity for any class: \033[0m";
    cin >> cap;
    cout << endl;
    cout << "\033[1;34mPlease choose a number for the desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Check student schedule" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Check class schedule" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Check students of a given class, UC or year" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Check number of students in a given minimum number of UCs" << endl;
    cout << "\033[1;36m[ 5 ]\033[0m" << " Check occupation of a given class, UC or year" << endl;
    cout << "\033[1;36m[ 6 ]\033[0m" << " Check the UCs with greatest number of students" << endl;
    cout << "\033[1;36m[ 7 ]\033[0m" << " Check the classes with the greatest number of students" << endl;
    cout << "\033[1;36m[ 8 ]\033[0m" << " Make changes" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    string id1;
    string uc1;
    string cl1;
    string uc2;
    string in;
    string in2;

    while (true) {

        switch (decision) {
            case 1:

                cout << "\033[1;34mWhich student id: \033[0m";
                cin >> in;
                Schedules_Checker::check_schedule_student(in);
                break;

            case 2:

                cout << "\033[1;34mWhich class: \033[0m";
                cin >> in;
                Schedules_Checker::check_schedule_class(in);
                break;

            case 3:

                cout << "\033[1;34mDo you want to check a class, UC or year?\033[0m\n";
                cout << "\033[1;36m[ 1 ]\033[0m" << " Class" << endl;
                cout << "\033[1;36m[ 2 ]\033[0m" << " UC" << endl;
                cout << "\033[1;36m[ 3 ]\033[0m" << " Year" << endl << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                if (decision == 1) {

                    cout << "\033[1;34mWhich UC: \033[0m";
                    cin >> in;
                    cout << "\033[1;34mWhich class: \033[0m";
                    cin >> in2;
                    ListStudents::check_class_students(in, in2);

                }
                else if (decision == 2) {

                    cout << "\033[1;34mWhich UC: \033[0m";
                    cin >> in;
                    ListStudents::check_UC_students(in);

                }
                else {

                    cout << "\033[1;34mWhich year: \033[0m";
                    cin >> in;
                    ListStudents::check_year_students(in);

                }
                break;

            case 4:

                cout << "\033[1;34mIn how many UCs do you want to check for: \033[0m";
                cin >> in;
                Ocupation::check_students_by_UCs(in);
                break;

            case 5:

                cout << "\033[1;34mDo you want to check the occupation of a class, UC or year: \033[0m";
                cout << "\033[1;36m[ 1 ]\033[0m" << " Class" << endl;
                cout << "\033[1;36m[ 2 ]\033[0m" << " UC" << endl;
                cout << "\033[1;36m[ 3 ]\033[0m" << " Year" << endl << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                if (decision == 1) {

                    cout << "\033[1;34mWhich class: \033[0m";
                    cin >> in;
                    Ocupation::check_class_occupation(in);

                }
                else if (decision == 2) {

                    cout << "\033[1;34mWhich UC: \033[0m";
                    cin >> in;
                    Ocupation::check_UC_occupation(in);

                }
                else {

                    cout << "\033[1;34mWhich year: \033[0m";
                    cin >> in;
                    Ocupation::check_year_occupation(in);

                }
                break;

            case 6:

                cout << "\033[1;34mHow many UCs would you like to be be presented with: \033[0m";
                cin >> in;
                Ocupation::greatest_number(in);
                break;

            case 7:

                cout << "\033[1;34mHow many classes would you like to be be presented with: \033[0m";
                cin >> in;
                Ocupation::most_students(in);
                break;

            case 8:

                cout << "\033[1;36m[ 1 ]\033[0m" << " Join UC" <<endl;
                cout << "\033[1;36m[ 2 ]\033[0m" << " Leave UC" <<endl;
                cout << "\033[1;36m[ 3 ]\033[0m" << " Swap UC" << endl;
                cout << "\033[1;36m[ 4 ]\033[0m" << " Swap class" << endl;
                cout << "\033[1;36m[ 5 ]\033[0m" << " Queued operations" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;

                cout << endl << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                switch (decision) {
                    case 1:

                        cout << "\033[1;34mStudent ID: \033[0m";
                        cin >> id1;
                        cout << endl << "\033[1;34mUC to join: \033[0m";
                        cin >> uc1;
                        cout << endl;
                        Changes::call_joinuc(id1, uc1, cap);
                        break;

                    case 2:
                        cout << "\033[1;34mStudent ID: \033[0m";
                        cin >> id1;
                        cout << endl << "\033[1;34mUC to leave: \033[0m";
                        cin >> uc1;
                        Changes::call_leaveuc(id1, uc1);
                        break;
                    case 3:
                        cout << "\033[1;34mStudent ID: \033[0m";
                        cin >> id1;
                        cout << endl << "\033[1;34mUC to leave: \033[0m";
                        cin >> uc1;
                        cout << endl << "\033[1;34mUC to join: \033[0m";
                        cin >> uc2;
                        Changes::call_swapuc(id1, uc1, uc2, cap);
                        break;

                    case 4:

                        cout << "\033[1;34mStudent ID: \033[0m";
                        cin >> id1;
                        cout << endl << "\033[1;34mUC in question: \033[0m";
                        cin >> uc1;
                        Changes::call_swapclass(id1, uc1, cap);
                        break;
/*
                    case 5:

                        cout << "\033[1;34mStudent ID: \033[0m";
                        cin >> id1;
                        cout << endl;
                        Changes::call_multi(id1, cap);
                        break;
*/
                    case 0:

                        break;

                    default:

                        cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                        break;
                }
                break;

            case 0:

                cerr << "Program closed" << endl;
                return 0;

            default:

                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                break;
        }

        cout << endl;
        cout << "\033[1;34mWish to do anything else?\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Check student schedule" << endl;
        cout << "\033[1;36m[ 2 ]\033[0m" << " Check class schedule" << endl;
        cout << "\033[1;36m[ 3 ]\033[0m" << " Check students of a given class, UC or year" << endl;
        cout << "\033[1;36m[ 4 ]\033[0m" << " Check number of students in a given minimum number of UCs" << endl;
        cout << "\033[1;36m[ 5 ]\033[0m" << " Check occupation of a given class, UC or year" << endl;
        cout << "\033[1;36m[ 6 ]\033[0m" << " Check the UCs with greatest number of students" << endl;
        cout << "\033[1;36m[ 7 ]\033[0m" << " Check the classes with the greatest number of students" << endl;
        cout << "\033[1;36m[ 8 ]\033[0m" << " Make changes" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;
    }
}

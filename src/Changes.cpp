#include "Changes.h"
#include "Ocupation.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <queue>
#include "Undo.h"


using namespace std;

void Changes::set_cjoined(string c)
{
    c_joined = c;
}

void Changes::set_cleft(string c)
{
    c_left = c;
}

void Changes::call_joinuc(string id, string uc, int cap, string cc, bool sw, bool undo) {

    ifstream file1("../schedule/students_classes.csv");
    ifstream file2("../schedule/classes_per_uc.csv");

    if (!file1.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    if (!file2.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    string line;
    string word;
    string name;
    vector <string> row;
    vector <string> ucs;
    vector <string> classes;

    getline(file2, line);
    getline(file1, line);

    while (getline(file2, line)) {
        row.clear();
        stringstream iss(line);

        getline(iss, word, ',');
        row.push_back(word);

        iss >> word;
        row.push_back(word);

        if (row[0] == uc) {
            classes.push_back(row[1]);
        }
    }

    while (getline(file1, line)) {

        row.clear();
        stringstream iss2(line);


        getline(iss2, word, ',');
        row.push_back(word);

        getline(iss2, word, ',');
        row.push_back(word);

        getline(iss2, word, ',');
        row.push_back(word);

        iss2 >> word;
        row.push_back(word);

        if (row[0] == id) {
            if (row[2] == uc) {
                if (!sw) {
                    cout << "\033[1;33mYou are already in that UC\033[0m" << endl << endl;
                    return;
                }
            }
            ucs.push_back(row[2]);
            name = row[1];
        }

    }

    if (ucs.size() < 7 || sw) {
        Changes::available_classes(classes, uc);
        int options = 1;
        int decision;

        if (!classes.empty()) {
            if (classes.size() != 1) {

                if (undo && Changes::check_conflicts(cc, uc, id)) {
                    ofstream filew;
                    filew.open("../schedule/students_classes.csv",ios::out | ios::app);
                    Undo::write_log(id, uc, cc, "joinuc", cap);
                    cout << endl << "\033[1;32mYou were assigned back to the class successfully\033[0m" << endl << endl;
                    Changes::set_cjoined(cc);
                    filew << id << "," << name << "," << uc << "," << cc << endl;
                    return;
                }
                cout << "\033[1;34mChoose one from the available classes of UC \033[0m" << uc << "\033[1;34m :\033[0m" << endl;
                for (auto it: classes) {

                    if (Ocupation::check_class_occupation_per_uc(it,uc) < cap) {
                        cout << "\033[1;36m[ \033[0m" << options << "\033[1;36m ]\033[0m" << " " << it << endl;
                        options++;
                    }
                }
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Cancel\033[0m" << endl;
                cout << endl << "\033[1;34mDecision: \033[0m";
                cin >> decision;

                if (decision == 0) {
                    return;
                }
                else if (Changes::check_conflicts(classes[decision - 1], uc, id)) {

                    ofstream filew;
                    filew.open("../schedule/students_classes.csv",ios::out | ios::app);
                    if (!sw) {
                        Undo::write_log(id, uc, classes[decision - 1], "joinuc", cap);
                        cout << endl << "\033[1;32mYou were assigned to the chosen class successfully\033[0m" << endl << endl;
                        Changes::set_cjoined(classes[decision-1]);

                    }
                    filew << id << "," << name << "," << uc << "," << classes[decision-1] << endl;

                }
                else {
                    cout << endl << "\033[1;31mWe could not assign you to the chosen class due to schedule conflicts\033[0m\n" << endl;
                    Changes::call_joinuc(id, uc, cap);
                }
            }
            else {
                if (undo && Changes::check_conflicts(cc, uc, id)) {
                    ofstream filew;
                    filew.open("../schedule/students_classes.csv",ios::out | ios::app);
                    Undo::write_log(id, uc, cc, "joinuc", cap);
                    cout << endl << "\033[1;32mYou were assigned back to the class successfully\033[0m" << endl << endl;
                    Changes::set_cjoined(cc);
                    filew << id << "," << name << "," << uc << "," << cc << endl;
                    return;
                }
                if (Changes::check_conflicts(classes[0], uc, id)) {
                    if (!sw) {
                        Undo::write_log(id,uc,classes[0],"joinuc",cap);
                        cout << "\033[1;32mYou were assigned to the following class as it was the only one available:  \033[0m" << classes[0] << endl << endl;
                        Changes::set_cjoined(classes[0]);
                    }
                    ofstream filew;
                    filew.open("../schedule/students_classes.csv", ios::out | ios::app);
                    filew << id << "," << name << "," << uc << "," << classes[0] << endl;

                }
                else {
                    cout << "\033[1;31mWe could not assign you to any class from the given UC due to schedule conflicts\033[0m" << endl << endl;
                    if (sw) {
                        return;
                    }
                }
            }
        }
        else {
            cout << "\033[1;31mThere are no available classes for you to join\033[0m" << endl << endl;
            if (sw) {
                return;
            }
        }
    }
    else {
        cout << "\033[1;31mYou cannot join any more UCs (Max. 7)\033[0m" << endl << endl;
    }

}


void Changes::call_leaveuc(string id, string uc, string ucj, string clas_joined, int cap, bool trigger, bool sw) {

    string line;
    string word;
    string cc;
    bool button = true;
    bool second_button = false;
    vector<string> row;

    bool in_uc = false;

    struct std {
        string id;
        string name;
        string uc;
        string cc;
    };
    std a = {"StudentCode","StudentName","UcCode","ClassCode"};
    vector<std> rawr;
    rawr.push_back(a);


    ifstream file("../schedule/students_classes.csv");
    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    getline(file, line);

    cout << endl;

    while (getline(file, line)) {

        row.clear();
        stringstream iss(line);

        getline(iss, word, ',');
        row.push_back(word);

        getline(iss, word, ',');
        row.push_back(word);

        getline(iss, word, ',');
        row.push_back(word);

        iss >> word;
        row.push_back(word);

        if (row[0]==id && row[2]==uc && button)
        {
            in_uc = true;
            cc = row[3];
            button = false;
            continue;
        }
        else if (row[0]==id && row[2]==uc && !button) {
            second_button = true;
        }
        a= {row[0],row[1],row[2],row[3]};
        rawr.push_back(a);
    }

    if(!in_uc && !second_button) {
        cout << "\033[1;33mYou are not enrolled in that UC\033[0m" << endl << endl;
        // Undo da join passada
        return;
    }

    file.close();

    ofstream fil("../schedule/students_classes.csv");
    if (!fil.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    for (auto l : rawr) {
        fil << l.id << "," << l.name << "," << l.uc << "," << l.cc << endl;
    }

    if (!sw) {
        cout << "\033[1;32mStudent \033[0m" << id << "\033[1;32m successfully removed from \033[0m" << uc << endl << endl;
        set_cleft(cc);
        Undo::write_log(id,uc,cc,"leaveuc",cap);
    }
    else if (sw && !trigger) {
        cout << "\033[1;32mSwapped from \033[0m" << uc << "\033[1;32m to \033[0m" << ucj << "\033[1;32m successfully \033[0m" << endl << endl;
    }
    else {
        cout << "\033[1;32mSwapped from \033[0m" << cc << "\033[1;32m to \033[0m" << clas_joined << "\033[1;32m successfully \033[0m" << endl << endl;
    }


}

void Changes::call_swapuc(string id, string ucl, string ucj, int cap) {
    Changes::call_joinuc(id, ucj, cap,"", true, false);
    Changes::call_leaveuc(id, ucl, ucj, "", cap,false, true);
    Undo::write_log(id,ucj,c_left,"swapuc", cap, ucl);
}

void Changes::call_swapclass(string id, string uc, int cap) {
    Changes::call_joinuc(id, uc, cap, "", true, false);
    Changes::call_leaveuc(id, uc, "", c_joined, cap, true,true);
    Undo::write_log(id,uc,c_joined,"swapclass",cap,"",c_left);
}

void Changes::call_multi(string id, int cap, queue<string> operations) {

    string in;

    cout << "\033[1;34mWhich operation would you like to execute first?\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Join UC" <<endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Leave UC" <<endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Swap UC" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Swap class" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Cancel queued operations\033[0m" << endl;

    int decision;
    cout << endl << "\033[1;34mDecision: \033[0m";
    cin >> decision;
    cout << endl;

    while (true) {
        switch (decision) {
            case 1:

                operations.push("joinuc");
                cout << "\033[1;34mUC to join: \033[0m";
                cin >> in;
                cout << endl;
                operations.push(in);
                break;

            case 2:

                operations.push("leaveuc");
                cout << "\033[1;34mUC to leave: \033[0m";
                cin >> in;
                cout << endl;
                operations.push(in);
                break;

            case 3:

                operations.push("swapuc");
                cout << "\033[1;34mUC to leave: \033[0m";
                cin >> in;
                operations.push(in);
                cout << "\033[1;34mUC to join: \033[0m";
                cin >> in;
                cout << endl;
                operations.push(in);
                break;

            case 4:

                operations.push("swapclass");
                cout << "\033[1;34mUC in question: \033[0m";
                cin >> in;
                cout << endl;
                operations.push(in);
                break;

            case 9:

                Changes::execute_requests(operations, id, cap);
                return;

            case 0:

                cout << endl;
                return;

            default:

                cout << "\033[0;31mUnrecognized option\033[0m" << endl << endl;
                break;
        }

        cout << "\033[1;34mWish to request any other operation or execute all requests previously made?\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Join UC" <<endl;
        cout << "\033[1;36m[ 2 ]\033[0m" << " Leave UC" <<endl;
        cout << "\033[1;36m[ 3 ]\033[0m" << " Swap UC" << endl;
        cout << "\033[1;36m[ 4 ]\033[0m" << " Swap class" << endl;
        cout << "\033[1;33m[ 9 ]\033[0m" << " Execute requests" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Cancel queued operations\033[0m" << endl;

        cout << endl << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;
    }
}

void Changes::execute_requests(queue<string> operations, string id, int cap) {

    string operation;
    string uc1;
    string uc2;

    while (!operations.empty()) {

        operation = operations.front();
        operations.pop();

        if (operation == "joinuc") {

            uc1 = operations.front();
            operations.pop();
            Changes::call_joinuc(id, uc1, cap);

        }
        else if (operation == "leaveuc") {

            uc1 = operations.front();
            operations.pop();
            Changes::call_leaveuc(id, uc1, "", "", cap);

        }
        else if (operation == "swapuc") {

            uc1 = operations.front();
            operations.pop();
            uc2 = operations.front();
            operations.pop();
            Changes::call_swapuc(id, uc1, uc2, cap);

        }
        else {

            uc1 = operations.front();
            operations.pop();
            Changes::call_swapclass(id, uc1, cap);

        }
    }

    cout << endl;
    cout << "\033[1;32mAll queued operations executed\033[0m" << endl << endl;
}

void Changes::available_classes(vector<string>& vect,string uc) {
    int max_students = 0;
    int min_students = 9999;
    string max_class = "";
    string min_class = "";
    vector <string> mins;
    int tam = 0;
    for(auto a: vect)
    {
        tam = Ocupation::check_class_occupation_per_uc(a,uc);
        if(tam > max_students){max_students=tam; max_class=a;}
        else if(tam <= min_students){min_students=tam;min_class=a;}
    }

    if(max_students-min_students==4)
    {
        vect.erase(find(vect.begin(), vect.end(), max_class));
        available_classes(vect, uc);
    }
    else if (max_students-min_students > 4) {
        mins.push_back(min_class);
        vect.erase(find(vect.begin(), vect.end(), min_class));
        for (auto it : vect) {
            tam = Ocupation::check_class_occupation_per_uc(it,uc);
            if (tam == min_students) {
                min_class = it;
                mins.push_back(min_class);
            }
        }
        vect.clear();
        vect = mins;
        return;
    }
    else
    {
        return;
    }
}

bool Changes::check_conflicts(string cc, string uc, string id) {

    ifstream file1("../schedule/students_classes.csv");
    ifstream file2("../schedule/classes.csv");

    if (!file1.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return 0;
    }

    if (!file2.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return 0;
    }

    string line1;
    string line2;
    string word1;
    string word2;
    string day_new;
    string day_old;
    string hour_start_new;
    string hour_start_old;
    string hour_finish_new;
    string hour_finish_old;

    vector <string> row1;
    vector <string> row2;

    getline(file1, line1);
    getline(file2, line2);

    struct sch
    {
        string day;
        string hs;
        string hf;
    };
    vector<sch> ra;

    while (getline(file2, line2)) {

        row2.clear();
        stringstream iss2(line2);

        getline(iss2, word2, ',');
        row2.push_back(word2);

        getline(iss2, word2, ',');
        row2.push_back(word2);

        getline(iss2, word2, ',');
        row2.push_back(word2);

        getline(iss2, word2, ',');
        row2.push_back(word2);

        getline(iss2, word2, ',');
        row2.push_back(word2);

        iss2 >> word2;
        row2.push_back(word2);

        if (row2[0] == cc && row2[1] == uc) {
            day_new = row2[2];
            hour_start_new = row2[3];
            hour_finish_new = to_string(stof(row2[3]) + stof(row2[4]));
            ra.push_back({day_new,hour_start_new,hour_finish_new});
        }
    }

    while (getline(file1, line1)) {

        row1.clear();
        stringstream iss1(line1);

        getline(iss1, word1, ',');
        row1.push_back(word1);

        getline(iss1, word1, ',');
        row1.push_back(word1);

        getline(iss1, word1, ',');
        row1.push_back(word1);

        iss1 >> word1;
        row1.push_back(word1);

        if (row1[0] == id) {

            ifstream file2("../schedule/classes.csv");

            if (!file2.is_open()) {
                cerr << "FAILED TO OPEN THE FILE" << endl;
                return 0;
            }

            getline(file2, line2);

            while (getline(file2, line2)) {

                row2.clear();
                stringstream iss2(line2);

                getline(iss2, word2, ',');
                row2.push_back(word2);

                getline(iss2, word2, ',');
                row2.push_back(word2);

                getline(iss2, word2, ',');
                row2.push_back(word2);

                getline(iss2, word2, ',');
                row2.push_back(word2);

                getline(iss2, word2, ',');
                row2.push_back(word2);

                iss2 >> word2;
                row2.push_back(word2);

                if (row1[2] == row2[1] && row1[3] == row2[0]) {
                    day_old = row2[2];
                    hour_start_old = row2[3];
                    hour_finish_old = to_string(stof(row2[3]) + stof(row2[4]));

                    for(auto a : ra)
                    {
                        if (a.day == day_old) {
                            if (a.hs > hour_start_old && hour_finish_old > a.hs || a.hf > hour_start_old && a.hf < hour_finish_old) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

void Changes::call_joinuc_force(string id, string name, string uc, string cl)
{
    ofstream filew;
    filew.open("../schedule/students_classes.csv", ios::out | ios::app);
    filew << id << "," << name << "," << uc << "," << cl << endl;
}
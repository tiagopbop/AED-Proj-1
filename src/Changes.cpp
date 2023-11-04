#include "Changes.h"
#include "Student.h"
#include "Ocupation.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <queue>
#include "Undo.h"

using namespace std;

void Changes:: call_joinuc(string id, string uc, int cap) {

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
                cout << "\033[1;33mYou are already in that UC\033[0m" << endl;
                return;
            }
            ucs.push_back(row[2]);
            name = row[1];
        }

    }

    if (ucs.size() < 7) {
        Changes::available_classes(classes, uc);
        int options = 1;
        int decision;

        if (!classes.empty()) {
            if (classes.size() != 1) {
                cout << "\033[1;34mChoose one from the available classes:\033[0m" << endl;
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

                    filew << id << "," << name << "," << uc << "," << classes[decision-1] << endl;
                    cout << endl << "\033[1;32mYou were assigned to the chosen class successfully\033[0m" << endl;
                }
                else {
                    cout << endl << "\033[1;31mWe could not assign you to the chosen class due to schedule conflicts\033[0m\n" << endl;
                    Changes::call_joinuc(id, uc, cap);
                }
            }
            else {
                if (Changes::check_conflicts(classes[0], uc, id)) {

                    ofstream filew;
                    filew.open("../schedule/students_classes.csv", ios::out | ios::app);
                    filew << id << "," << name << "," << uc << "," << classes[0] << endl;
                    cout << "\033[1;32mYou were assigned to the following class as it was the only one available:  \033[0m" << classes[0] << endl;
                }
                else {
                    cout << "\033[1;31mWe could not assign you to any class from the given UC due to schedule conflicts\033[0m" << endl;
                }
            }
        }
        else {
            cout << "\033[1;31mThere are no available classes for you to join\033[0m" << endl;
        }
    }
    else {
        cout << "\033[1;31mYou cannot join any more UCs (Max. 7)\033[0m" << endl;
    }
}

void Changes::call_leaveuc(string id, string uc, bool trigger) {

    string line;
    string word;
    string cc;
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

        if(row[0]==id && row[2]==uc)
        {
            in_uc = true;
            cc = row[3];
            continue;
        }
        else
        {
            a= {row[0],row[1],row[2],row[3]};
            rawr.push_back(a);
        }
    }

    if(!in_uc) {
        cout << "\033[1;33mYou are not enrolled in that UC\033[0m" << endl;
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

    if (!trigger) {
        cout << "\033[1;32mStudent \033[0m" << id << "\033[1;32m successfully removed from \033[0m" << uc << endl << endl;
    }
    else {
        cout << "\033[1;32mStudent \033[0m" << id << "\033[1;32m successfully removed from \033[0m" << cc << endl << endl;
    }
}

void Changes::call_swapuc(string id, string ucl, string ucj, int cap) {
    Changes::call_leaveuc(id, ucl);
    Changes::call_joinuc(id, ucj, cap);
}

void Changes::call_swapclass(string id, string uc, int cap) {
    Changes::call_leaveuc(id, uc, true);
    Changes::call_joinuc(id, uc, cap);
}

void Changes::call_multi(string id, int cap) {

    queue <string> operations;


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
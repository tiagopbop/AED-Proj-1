#include "Changes.h"
#include "Student.h"
#include "Ocupation.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void Changes:: call_joinuc(string id, string uc) {

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
                cout << endl << "You are already in that UC" << endl;
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
                cout << "Choose one from the available classes: " << endl;
                for (auto it: classes) {
                    cout << options << ": " << it << endl;
                    options++;
                }
                cout << endl << "Decision: ";
                cin >> decision;

                if (Changes::check_conflicts(classes[decision - 1], uc, id)) {
                    
                    cout << endl << "You were assigned to this class successfully: " << classes[decision - 1] << endl;
                }
                else {
                    cout << "We could not assign you to the chosen class due to schedule conflicts" << endl;
                }
            }
            else {
                cout << "You were assigned to this class:  " << classes[0] << endl; // Assumindo que n cria conflito
            }
        }
        else {
            cout << "There are no available classes for you to join" << endl;
        }
    }
    else {
        cout << "You cannot join any more UCs (Max. 7)" << endl;
    }
}

void Changes::call_leaveuc(string id, string uc) {

}

void Changes::call_swapuc(string id, string ucl, string ucj) {

}

void Changes::call_swapclass(string id, string uc) {

}

void Changes::call_multi(string id, string uc, string cass) {

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


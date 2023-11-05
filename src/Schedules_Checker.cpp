#include "Schedules_Checker.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>



void Schedules_Checker::check_schedule_student(const string& id) {

    ifstream file("../schedule/students_classes.csv");

    string line;
    string word;
    vector<string> row;

    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    getline(file, line);

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

        if (row[0] == id) {
            Schedules_Checker::print_schedule_student(row[2], row[3]);
        }
    }
}
void Schedules_Checker::print_schedule_student(const string& uc, const string& cc) {

    ifstream file("../schedule/classes.csv");

    string line;
    string word;
    vector<string> row;

    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    getline(file, line);

    while (getline(file, line)) {

        row.clear();
        stringstream iss(line);

        getline(iss, word, ',');
        row.push_back(word);

        getline(iss, word, ',');
        row.push_back(word);

        getline(iss, word, ',');
        row.push_back(word);

        getline(iss, word, ',');
        row.push_back(word);

        getline(iss, word, ',');
        row.push_back(word);

        iss >> word;
        row.push_back(word);

        if (row[0] == cc && row[1] == uc) {
            cout << endl;
            if (row[3].size() > 2) {
                basic_string<char> fla = row[3];
                cout << "\033[0;36m▶  \033[0m" << row[2] << "\033[0;36m  ◆ \033[0m" << "\033[0;36m At \033[0m" << round(stoi(fla)) << ":30"
                     << "\033[0;36m  ◆  \033[0m" << row[4] << "\033[0;36m hour(s) \033[0m" << "\033[0;36m ◆  \033[0m"
                     << row[5] << " " << row[1] << "\033[0;36m lesson\033[0m" << "\033[0;36m  ◀\033[0m" << endl;
            }
            else {
                cout << "\033[0;36m▶  \033[0m" << row[2] << "\033[0;36m  ◆ \033[0m" << "\033[0;36m At \033[0m" << row[3]
                     << "\033[0;36m  ◆  \033[0m" << row[4] << "\033[0;36m hour(s) \033[0m" << "\033[0;36m ◆  \033[0m"
                     << row[5] << " " << row[1] << "\033[0;36m lesson\033[0m" << "\033[0;36m  ◀\033[0m" << endl;
            }
        }
    }
    cout << endl;
}

void Schedules_Checker::check_schedule_class(const string& in) {

    ifstream file("../schedule/classes.csv");

    string line;
    string word;
    vector<string> row;

    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    getline(file, line);

    while (getline(file, line)) {

        row.clear();
        stringstream iss(line);

        getline(iss, word, ',');
        row.push_back(word);

        getline(iss, word, ',');
        row.push_back(word);

        getline(iss, word, ',');
        row.push_back(word);

        getline(iss, word, ',');
        row.push_back(word);

        getline(iss, word, ',');
        row.push_back(word);

        iss >> word;
        row.push_back(word);

        if (row[0] == in) {
            cout << endl;
            if (row[3].size() > 2) {
                basic_string<char> fla = row[3];
                cout << "\033[0;36m▶  \033[0m" << row[2] << "\033[0;36m  ◆ \033[0m" << "\033[0;36m At \033[0m" << round(stoi(fla)) << ":30"
                     << "\033[0;36m  ◆  \033[0m" << row[4] << "\033[0;36m hour(s) \033[0m" << "\033[0;36m ◆  \033[0m"
                     << row[5] << " " << row[1] << "\033[0;36m lesson\033[0m" << "\033[0;36m  ◀\033[0m" << endl;
            }
            else {
                cout << "\033[0;36m▶  \033[0m" << row[2] << "\033[0;36m  ◆ \033[0m" << "\033[0;36m At \033[0m" << row[3]
                     << "\033[0;36m  ◆  \033[0m" << row[4] << "\033[0;36m hour(s) \033[0m" << "\033[0;36m ◆  \033[0m"
                     << row[5] << " " << row[1] << "\033[0;36m lesson\033[0m" << "\033[0;36m  ◀\033[0m" << endl;
            }
        }
    }
    cout << endl;
}
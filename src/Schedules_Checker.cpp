#include "Schedules_Checker.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


void Schedules_Checker::check_schedule_student(string id) {

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
void Schedules_Checker::print_schedule_student(string uc, string cc) {

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
            cout << "\033[1;32m| \033[0m" << row[2] << "\033[1;32m - At \033[0m" << row[3] << "\033[1;32m - \033[0m" << row[4] << "\033[1;32m hour(s) - \033[0m" << row[5] << " " << row[1] << "\033[1;32m lesson |\033[0m" << endl;
        }
    }
    cout << endl;
}

void Schedules_Checker::check_schedule_class(string in) {

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
            cout << "\033[1;32m| \033[0m" << row[2] << "\033[1;32m - At \033[0m" << row[3] << "\033[1;32m - \033[0m" << row[4] << "\033[1;32m hour(s) - \033[0m" << row[5] << " " << row[1] << "\033[1;32m lesson |\033[0m" << endl;
        }
    }
    cout << endl;
}
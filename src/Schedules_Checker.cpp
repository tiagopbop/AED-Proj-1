#include "Schedules_Checker.h"
#include <string>
#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Class.h"
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
            cout << "| " << row[2] << " - At " << row[3] << " - " << row[4] << " hour(s) - " << row[5] << " " << row[1] << " lesson |" << endl;
        }
    }
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
            cout << "| " << row[2] << " - At " << row[3] << " - " << row[4] << " hour(s) - " << row[5] << " " << row[1] <<" lesson |" << endl;
        }
    }
}
//
// Created by loading on 03-11-2023.
//

#include "ListStudents.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
void ListStudents::check_class_students(string id) {

    ifstream file("../schedule/students_classes.csv");

    string line;
    string word;
    vector<string> row;
    vector<string> past_names;

    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    getline(file, line);

    cout << endl;
    cout << "Class " << id << " students:" << endl;

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

        auto it = find(past_names.begin(), past_names.end(), row[1]);

        if (row[3] == id && it == past_names.end()) {
            past_names.push_back(row[1]);
            cout << row[1] << " - " << row[0] << endl;
        }
    }
}

void ListStudents::check_UC_students(string id) {

    ifstream file("../schedule/students_classes.csv");

    string line;
    string word;
    vector<string> row;

    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    getline(file, line);

    cout << endl;
    cout << "UC " << id << " students:" << endl;

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

        if (row[2] == id) {
            cout << row[1] << " - " << row[0] << endl;
        }
    }
}

void ListStudents::check_year_students(string id) {

    ifstream file("../schedule/students_classes.csv");

    string line;
    string word;
    vector<string> row;
    vector<string> past_names;

    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    getline(file, line);

    cout << endl;
    cout << "Year " << id << " students" << endl;

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

        auto it = find(past_names.begin(), past_names.end(), row[1]);

        if (row[3].substr(0,1) == id && it == past_names.end()) {
            past_names.push_back(row[1]);
            cout << row[1] << " - " << row[0] << endl;
        }
    }
}

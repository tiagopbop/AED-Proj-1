#include "Ocupation.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

void Ocupation::most_students(const string& in) {

    int pos = 0;

    ifstream file("../schedule/classes_per_uc.csv");
    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }
    string line;
    string word;
    vector<string> row;
    getline(file, line);

    vector<string> uc;
    vector<string> cl;
    vector<int> count;

    while (getline(file, line)) {

        row.clear();
        stringstream iss(line);

        getline(iss, word, ',');
        row.push_back(word);

        iss >> word;
        row.push_back(word);

        uc.push_back(row[0]);
        cl.push_back(row[1]);
        count.push_back(Ocupation::check_class_occupation_per_uc(row[1],row[0]));
        pos++;

    }

    for (int a = 0; a < stoi(in); a++) {
        int topIndex = 0;
        int topCount = count[0];
        for (int i = 1; i < pos; i++) {
            if (count[i] > topCount) {
                topCount = count[i];
                topIndex = i;
            }
        }

        cout << topCount << "\033[1;32m students from \033[0m" << cl[topIndex] << "\033[1;32m of \033[0m" << uc[topIndex] << endl;
        count[topIndex] = 0;
    }
    cout << endl;
}


void Ocupation::check_students_by_UCs(const string& in)
{
    ifstream file("../schedule/students_classes.csv");

    string line;
    string word;
    vector<string> row;
    string before;
    int mid_count = 0;
    int count = 0;

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

        if (row[0] != before) {

            if (mid_count >= stoi(in)) {
                count++;
            }

            before = row[0];
            mid_count = 1;

        }
        else {
            mid_count++;
        }
    }

    cout << endl;
    cout << "\033[1;32mNumber of students registered in at least \033[0m" << in << "\033[1;32m UCs: \033[0m" << count << endl << endl;
}

void Ocupation::check_class_occupation(const string& id,const string& uc) {

    ifstream file("../schedule/students_classes.csv");

    string line;
    string word;
    vector<string> row;
    vector<string> past_names;
    int count = 0;

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

        auto it = find(past_names.begin(), past_names.end(), row[1]);

        if (row[3] == id && it == past_names.end() && row[2] == uc) {
            past_names.push_back(row[1]);
            count++;
        }
    }
    cout << endl << "\033[1;32mNumber of students registered in class \033[0m"<< id << "\033[1;32m of UC \033[0m" << uc << "\033[1;32m: \033[0m" << count << endl << endl;
}

int Ocupation::check_class_occupation_per_uc(const string& id,const string& uc) {

    ifstream file("../schedule/students_classes.csv");

    string line;
    string word;
    vector<string> row;
    vector<string> past_names;
    int count = 0;

    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return 0;
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

        auto it = find(past_names.begin(), past_names.end(), row[1]);

        if (row[3] == id && it == past_names.end() && row[2] == uc) {
            past_names.push_back(row[1]);
            count++;
        }
    }
    return count;
}

void Ocupation::check_UC_occupation(const string& id) {
    ifstream file("../schedule/students_classes.csv");

    string line;
    string word;
    vector<string> row;
    int count = 0;

    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    getline(file, line);

    cout << endl;
    cout << "\033[1;32mNumber of students registered in UC \033[0m" << id <<"\033[1;32m: \033[0m";

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
            count++;
        }
    }
    cout << count << endl << endl;
}

void Ocupation::check_year_occupation(const string& id) {
    ifstream file("../schedule/students_classes.csv");

    string line;
    string word;
    vector<string> row;
    vector<string> past_names;
    int count = 0;

    if (!file.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    getline(file, line);

    cout << endl;
    cout << "\033[1;32mNumber of students registered in year \033[0m"<< id << "\033[1;32m: \033[0m";

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
            count++;
        }
    }
    cout << count << endl << endl;
}

void Ocupation::greatest_number(const string& id) {

    ifstream file("../schedule/students_classes.csv");

    string line;
    string word;
    vector<string> row;

    const int MAX = 10000;
    string words[MAX];
    int inst[MAX];
    int count = 0;

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

        for (int i = 0; i < count; i++) {
            if (row[2] == words[i]) {
                inst[i]++;
                break;
            }
        }
        words[count] = row[2];
        inst[count] = 1;
        count++;
    }


    for (int a = 0; a < stoi(id); a++) {
        int topIndex = 0;
        int topCount = inst[0];
        string topWord = words[0];

        for (int i = 1; i < count; i++) {
            if (inst[i] > topCount) {
                topCount = inst[i];
                topIndex = i;
            }
        }
        topWord=words[topIndex];
        cout << topCount << "\033[1;32m students in \033[0m" << topWord << endl;
        inst[topIndex] = 0;
    }
    cout << endl;
}
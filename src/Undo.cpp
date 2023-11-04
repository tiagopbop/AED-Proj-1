#include "Undo.h"
#include "Changes.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


void Undo::set_lastid(string id) {
    last_id = id;
}

void Undo::set_lastuc(string uc) {
    last_uc = uc;

}

void Undo::set_lastclass(string cc) {
    last_class = cc;
}

void Undo::set_lastop(string op) {
    last_op = op;
}

void Undo::write_log(string id, string ucj, string cc, string op,string cap) {

    ofstream logia;
    logia.open("../schedule/log.csv",ios::out | ios::app);

    if (!logia.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    set_lastid(id);
    set_lastuc(ucj);
    set_lastclass(cc);
    set_lastop(op);

    logia << id << "," << ucj << "," << cc << "," << op << endl;
    logia.close();
}


void Undo::go_back()
{
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
    std a = {"StudentCode","UcCode","ClassCode","Operation"};
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

        if(row[0]==last_id && row[1]==last_uc && row[2]==last_class && row[3]==last_op)
        {
            continue;
        }
        else
        {
            a= {row[0],row[1],row[2],row[3]};
            rawr.push_back(a);
        }
    }

    ofstream fil("../schedule/log.csv");
    if (!fil.is_open()) {
        cerr << "FAILED TO OPEN THE FILE" << endl;
        return;
    }

    for (auto l : rawr) {
        fil << l.id << "," << l.name << "," << l.uc << "," << l.cc << endl;
    }



    if(last_op=="joinuc")
    {
        Changes::call_leaveuc(last_id, last_uc);
    }

    else if(last_op == "leaveuc")
    {
        Changes::call_joinuc(last_id,last_uc,cap);



    else if(last_op == "swapuc")
    {
        Changes::call_leaveuc(last_id,last_uc);
    }

}





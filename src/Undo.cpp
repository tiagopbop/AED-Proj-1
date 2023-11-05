#include "Changes.h"
#include <iostream>
#include <fstream>
#include <utility>
#include "Undo.h"
using namespace std;


void Undo::set_lastid(string id) {
    last_id = std::move(id);
}

void Undo::set_lastuc(string uc) {
    last_uc = std::move(uc);
}

void Undo::set_lastclass(string cc) {
    last_class = std::move(cc);
}

void Undo::set_lastop(string op) {
    last_op = std::move(op);
}
void Undo::set_ucl(string uc) {
    ucl = std::move(uc);
}
void Undo::set_undo(bool undo) {
    last_undo = undo;
}

void Undo::write_log(const string& id, const string& ucj, const string& cc, const string& op, string ucl2, bool undo) {

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
    set_ucl(std::move(ucl2));
    set_undo(undo);
    if (!undo) {
        logia << id << "," << ucj << "," << cc << "," << op << ",false" << endl;
    }
    else {
        logia << id << "," << ucj << "," << cc << "," << op << ",true" << endl;
    }
    logia.close();
}


void Undo::go_back(int cap) {

    if (last_op == "joinuc") {
        Changes::call_leaveuc(last_id, last_uc, "", "", cap, false, false, true);
    }
    else if (last_op == "leaveuc") {
        Changes::call_joinuc(last_id, last_uc, cap, last_class,false, true);
    }
    else if (last_op == "swapuc") {
            Changes::call_leaveuc(last_id, last_uc, "", "", cap, false, false, true);
            Changes::call_joinuc(last_id,ucl,cap, last_class, false, true);
    }
    else if(last_op == "swapclass")
    {
        Changes::call_leaveuc(last_id, last_uc, "", "", cap, false, false, true);
        Changes::call_joinuc(last_id,last_uc, cap, last_class, false, true);
    }
    set_undo(true);
}

void Undo::check_last() {
    cout << "\033[1;33mID: \033[0m" << last_id << endl;
    cout << "\033[1;33mUC: \033[0m" << last_uc << endl;
    cout << "\033[1;33mClass left (if Operation = leaveuc) or joined (if Operation = swapuc/swapclass/joinuc): \033[0m" << last_class << endl;
    cout << "\033[1;33mOperation: \033[0m" << last_op << endl;
    cout << "\033[1;33mUndoOperation: \033[0m" << last_undo << endl << endl;
}




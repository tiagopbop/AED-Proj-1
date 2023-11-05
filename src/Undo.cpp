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
void Undo::set_ucl(string uc) {
    ucl = uc;
}

void Undo::write_log(string id, string ucj, string cc, string op,int cap, string ucl, string cl_l) {

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
    set_ucl(ucl);
    logia << id << "," << ucj << "," << cc << "," << op << endl;
    logia.close();
}


void Undo::go_back(int cap) {

    if (last_op == "joinuc") {
        Changes::call_leaveuc(last_id, last_uc, "", "", cap);
    }
    else if (last_op == "leaveuc") {
        Changes::call_joinuc(last_id, last_uc, cap, last_class,false, true);
    }
    else if (last_op == "swapuc") {
            Changes::call_leaveuc(last_id, last_uc, "", "", cap, false, false);
            Changes::call_joinuc(last_id,ucl,cap, last_class, false, true);
    }
    else if(last_op == "swapclass")
    {
        Changes::call_leaveuc(last_id, last_uc, "", "", cap, false, false);
        Changes::call_joinuc(last_id,last_uc, cap, last_class, false, true);
    }
}




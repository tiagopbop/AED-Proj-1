#ifndef REMAKE_CHANGES_H
#define REMAKE_CHANGES_H


#include <string>
#include <vector>
#include <queue>

using namespace std;

class Changes {
private:
    static string c_joined;
    static string c_left;

public:

    static void set_cjoined(string c);

    static void call_joinuc(string id, string uc, int cap, string cc = "", bool sw = false, bool undo = false);

    static void set_cleft(string c);

    static void call_leaveuc(string id, string uc, string ucj, string clas_joined, int cap, bool trigger = false, bool sw = false);

    static void call_swapuc(string id, string ucl, string ucj, int cap);

    static void call_swapclass(string id, string uc, int cap);

    static void call_multi(string id, int cap, queue<string> operations);

    static void execute_requests(queue<string> operations, string id, int cap);

    static void available_classes(vector<string> &vect,string uc);

    static bool check_conflicts(string cc, string uc, string id);

    void call_joinuc_force(string id, string name, string uc, string cl);
};

string Changes::c_joined;
string Changes::c_left;

#endif //REMAKE_CHANGES_H

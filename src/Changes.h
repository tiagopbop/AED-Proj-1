#ifndef REMAKE_CHANGES_H
#define REMAKE_CHANGES_H


#include <string>
#include <vector>
#include <queue>

using namespace std;

class Changes {
private:
    int a;

public:
    static void call_joinuc(string id, string uc, int cap, bool sw = false);

    static void call_leaveuc(string id, string uc, bool trigger = false, bool sw = false);

    static void call_swapuc(string id, string ucl, string ucj, int cap);

    static void call_swapclass(string id, string uc, int cap);

    static void call_multi(string id, int cap, queue<string> operations);

    static void execute_requests(queue<string> operations, string id, int cap);

    static void available_classes(vector<string> &vect,string uc);

    static bool check_conflicts(string cc, string uc, string id);

    void call_joinuc_force(string id, string name, string uc, string cl);
};


#endif //REMAKE_CHANGES_H

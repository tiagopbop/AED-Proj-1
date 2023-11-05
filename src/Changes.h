#ifndef REMAKE_CHANGES_H
#define REMAKE_CHANGES_H


#include <string>
#include <vector>
#include <queue>

using namespace std;

class Changes {
private:
    inline static string c_joined;
    inline static string c_left;
    inline static bool success = true;

public:

    static void set_cjoined(string c);

    static void call_joinuc(const string& id, const string& uc, int cap, const string& cc = "", bool sw = false, bool undo = false, bool trigger = false);

    static void set_cleft(string c);

    static void call_leaveuc(const string& id, const string& uc, const string& ucj, const string& clas_joined, int cap, bool trigger = false, bool sw = false, bool undo = false);

    static void call_swapuc(const string& id, const string& ucl, const string& ucj, int cap);

    static void call_swapclass(const string& id, const string& uc, int cap);

    static void call_multi(const string& id, int cap, queue<string> operations);

    static void execute_requests(queue<string> operations, const string& id, int cap);

    static void available_classes(vector<string> &vect,const string& uc);

    static bool check_conflicts(const string& cc, const string& uc, const string& id);

};


#endif //REMAKE_CHANGES_H

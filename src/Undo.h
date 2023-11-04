#ifndef REMAKE_UNDO_H
#define REMAKE_UNDO_H

#include <string>
using namespace std;

class Undo {
private:
    static string last_id;
    static string last_uc;
    static string last_class;
    static string last_op;
    static string ucl;
    static string last_name;
    static string cl_left;

public:
    static void set_lastid(string id);
    static void set_lastuc(string uc);
    static void set_lastclass(string cc);
    static void set_lastop(string op);
    static void set_ucl(string ucl);
    static void set_name(string name);
    static void set_clleft(string cll);
    static void write_log(string id,  string uc, string cc, string op, int cap, string ucl ="",string cl_left = "");
    void go_back(int cap);

};


#endif //REMAKE_UNDO_H

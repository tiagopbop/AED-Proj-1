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

public:
    static void set_lastid(string id);
    static void set_lastuc(string uc);
    static void set_lastclass(string cc);
    static void set_lastop(string op);
    static void set_ucl(string ucl);
    static void write_log(string id, string uc, string cc, string op, int cap, string ucl ="");
    void go_back();
};


#endif //REMAKE_UNDO_H

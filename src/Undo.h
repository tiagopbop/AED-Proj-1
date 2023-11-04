#ifndef REMAKE_UNDO_H
#define REMAKE_UNDO_H

#include <string>
using namespace std;

class Undo {
private:
    string last_id;
    string last_uc;
    string last_class;
    string last_op;

public:
    void set_lastid(string id);
    void set_lastuc(string uc);
    void set_lastclass(string cc);
    void set_lastop(string op);
    void write_log(string id, string uc, string cc, string op,string cap);
    void go_back();
};


#endif //REMAKE_UNDO_H

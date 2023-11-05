#ifndef REMAKE_UNDO_H
#define REMAKE_UNDO_H

#include <string>
using namespace std;

class Undo {
private:
    inline static string last_id;
    inline static string last_uc;
    inline static string last_class;
    inline static string last_op;
    inline static string ucl;
    inline static string last_name;
    inline static bool last_undo;

public:
    static void set_lastid(string id);
    static void set_lastuc(string uc);
    static void set_lastclass(string cc);
    static void set_lastop(string op);
    static void set_ucl(string ucl);
    static void set_undo(bool undo);
    static void write_log(const string& id,  const string& uc, const string& cc, const string& op, string ucl ="", bool undo = false);
    static void go_back(int cap);
    static void check_last();

};

#endif //REMAKE_UNDO_H

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

    /**
    * @brief Write a log entry to a log file.
    *
    * @param id The unique identifier of the student.
    * @param ucj The code of the university class (UC) to join.
    * @param cc The class code (CC) for the class.
    * @param op The type of operation to log (e.g., "joinuc," "leaveuc," "swapuc," "swapclass").
    * @param ucl2 The code of the university class (UC) to leave (optional).
    * @param undo A boolean flag indicating whether the operation is an undo action (true) or not (false).
    *
    * This function appends a log entry to a log file, recording student operations such as joining or leaving university
    * classes and classes. The log entry includes student ID, UC code, class code, operation type, and an undo flag.
    */
    static void write_log(const string& id,  const string& uc, const string& cc, const string& op, string ucl ="", bool undo = false);

    /**
    * @brief Reverts the most recent student operation and sets an undo flag.
    *
    * @param cap The capacity (maximum number of students) for a class.
    *
    * This function is used to undo the most recent student operation and sets an undo flag to indicate that the operation is
    * being reversed. It determines the type of operation (e.g., joinuc, leaveuc, swapuc, swapclass) performed and invokes
    * the appropriate corresponding operation to revert the change. The student's previous state is restored.
    */
    static void go_back(int cap);
    static void check_last();

};

#endif //REMAKE_UNDO_H

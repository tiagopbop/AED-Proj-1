//
// Created by loading on 03-11-2023.
//

#ifndef REMAKE_UNDO_H
#define REMAKE_UNDO_H

#include <string>
using namespace std;

class Undo {
private:
    string last_op;
public:
    void write_log();

};


#endif //REMAKE_UNDO_H

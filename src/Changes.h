//
// Created by loading on 03-11-2023.
//

#ifndef REMAKE_CHANGES_H
#define REMAKE_CHANGES_H


#include <string>
#include <vector>
using namespace std;

class Changes {
private:
    int a;
public:
    static void call_joinuc(string id, string uc);
    static void call_leaveuc(string id, string uc);
    static void call_swapuc(string id, string ucl, string ucj, string cass);
    static void call_swapclass(string id, string uc, string clas);
    static void call_multi(string id, string uc, string cass);

    //  static void available_classes(vector& v);

    static void available_classes(vector<string> &vect,string uc);

    static bool check_conflicts(string cc, string uc, string id);
};


#endif //REMAKE_CHANGES_H

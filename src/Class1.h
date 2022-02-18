//
// Created by EA on 10.11.2020.
//
#ifndef UNTITLED_CLASS1_H
#define UNTITLED_CLASS1_H
#include <string>
using namespace std;

class Class1 {
public:
    static int main();
    static int opennum;
    static int sayim;
    static int stockarray[3];
    static int movepile(int source_pile_num, int source_pile_card_index, int destination_pile_num);
    static int open(int pile_num);
    static void openstock();
    static void numberstock();
    static int movewaste(int destination_pile_num);
    static int movetofpile(int pilenum);
    static int movetofoundationwaste();
    static int sayac;
    static int movemethod(int x, int numsub, string str1 , int pilenum, int index1);
    static string exit();
    static int movefoundation(int sourcefnum, int desninationnum);
};
#endif //UNTITLED_CLASS1_H

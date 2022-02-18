//
// Created by EA on 8.11.2020.
//
#include "ClassArray.h"
#include "Class1.h"
#include "Class2.h"
#include "ClassFile.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

char ClassArray::deck[50];
char ClassArray::commands[50];
char ClassArray::output[50];

string ClassArray::deckArray[52];
string ClassArray::array2[12][24];
string ClassArray::arrayyedek[12][24];
int count;


static void composeArray(){   //for open and closed card situations

    for(int j = 0;j<24;j++) {
        ClassArray::arrayyedek[0][j] = ClassArray::array2[0][j];
    }
    for(int i =5 ;i<12;i++){
        for(int j = 0;j<24;j++){
            if(ClassArray::array2[i][j] != "NULL"){
                if(i-5==j){
                    ClassArray::arrayyedek[i][j] = ClassArray::array2[i][j];
                }
                else{
                    ClassArray::arrayyedek[i][j] = "@@@";  //if is closed
                }
            }
            else{
                ClassArray::arrayyedek[i][j] = "NULL";
            }
        }
    }
}

static void readingDeck(){   //deck txt
    string x;
    ifstream inFile;
    int cnt= 0;
    inFile.open(ClassArray::deck);
    if (!inFile) {
        //exit(1); // terminate with error
    }
    while (inFile >> x) {
        ClassArray::deckArray[cnt] = x;
        cnt++;
    }
    inFile.close();
}


static void readingCommand() {  //command txt
    ifstream inFile1;
    inFile1.open(ClassArray::commands);//"command.txt"
    int j = 0;
    if (!inFile1) {
        //exit(1); // terminate with error
    }
    string str;
    while (getline(inFile1, str)) {
        count++;
    }
    inFile1.close();

    inFile1.open(ClassArray::commands);   //creating command array
    string pString[count+1];

    while (getline(inFile1, str)) {// output the line
        pString[j] = str;
        j++;
    }
    inFile1.close();
    Class2::commandfunc(pString,count+1);   //going movement
}

static void reverseArray(string arr[]){   //reversing deck array
    for (int low = 24, high =51; low < high; low++, high--){
        string temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
}

static void fixcolumn(){
    int x = 0;
    int i = 0;
    int sayim=0;
    for(int j=0;j<24;j++){
        ClassArray::array2[0][j] = ClassArray::deckArray[j];
    }

    for(int j=1;j<5;j++) {
        for (int z = 1; z < 24; z++) {
            ClassArray::array2[j][z] = "NULL";
        }
    }
    while (i < 28) {
        ClassArray::array2[x + 5][0] = ClassArray::deckArray[24 + x];
        i++;
        x++;
        int y = 6;                 //fixing row and column in my deck array
        int z = 6;
        for (int j = 0; j < x - 1; j++) {
            ClassArray::array2[x - 1 + 5][j + 1] = ClassArray::deckArray[24 + x - 1 + z];
                i++;
                --y;
                z = z + y;
                sayim = j;
        }
        for (int a = x; a < 24; a++) {
            if (x == 1) {
                ClassArray::array2[x - 1 + 5][sayim + 1] = "NULL";
            } else {
                ClassArray::array2[x - 1 + 5][sayim + 2] = "NULL";
            }
            sayim++;
        }
    }
}


int ClassArray::main() {
    readingDeck();
    reverseArray(ClassArray::deckArray);
    fixcolumn();
    composeArray();
    readingCommand();
    return 0;
}
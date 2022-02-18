//
// Created by EA on 13.11.2020.
//
#include "Class2.h"
#include "ClassFile.h"
#include "Class1.h"
#include "ClassArray.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
string str1;
string arrayinsert[5];


void Class2::removeDupWord(string str){   //taking int from command txt line
    istringstream ss(str);
    string word; // for storing each word
    int index=0;
    // Traverse through all words
    // while loop till we get
    // strings to store in string word
    while (ss >> word){
        // print the read word
        str1=word;
        arrayinsert[index]=(str1);
        //cout << word << "\n";
        index++;
    }
}

void Class2::commandfunc(string *pString,int length) {
    ClassFile::creating();    //creating file txt
    Class1::numberstock();
    std::ofstream outfile;
    outfile.open(ClassArray::output, std::ios_base::app); // append instead of overwrite
    outfile<<"\n";
    outfile<<"@@@ ___ ___ ___         ___ ___ ___ ___";
    outfile<<"\n\n";
    for(int j = 0 ; j<8;j++){
        for(int i = 5 ; i<12;i++){
            if(ClassArray::arrayyedek[i][j] != "NULL"){
                outfile<<ClassArray::arrayyedek[i][j]<< "   ";
            }
            else{
                outfile<<"      ";
            }
        }
        outfile << "\n";
    }
    if(length == 0){

    }
    outfile.close();

    for (int i = 0; i < length; i++) {

        if(pString[i].find("move to foundation pile")<pString[i].length()){
            removeDupWord(pString[i]);
            std::stringstream ss;
            ss << str1;
            int num;     //converting int
            ss >> num;
            std::ofstream outfile;
            outfile.open(ClassArray::output, std::ios_base::app);
            int x = Class1::movetofpile(num);
            outfile<<pString[i]<<"\n\n";    //movement name
            if(x==1){
                outfile<<"Invalid Move!"<<"\n\n";
            }
            outfile<<"****************************************"<<"\n\n";
            outfile.close();
            ClassFile::main(pString[i]);
        }
        else if(pString[i].find("move to foundation waste")<pString[i].length()){
            std::ofstream outfile;
            outfile.open(ClassArray::output, std::ios_base::app);
            int x = Class1::movetofoundationwaste();
            outfile<<pString[i]<<"\n\n";  //movement name
            if(x==1){                          //if it is invalid
                outfile<<"Invalid Move!"<<"\n\n";
            }
            outfile<<"****************************************"<<"\n\n";
            outfile.close();
            ClassFile::main(pString[i]);

        }
        else if(pString[i].find("move waste")<pString[i].length()){
            removeDupWord(pString[i]);
            std::stringstream ss;
            ss << str1;
            int num;
            ss >> num;                //converting int
            int x = Class1::movewaste(num);
            std::ofstream outfile;
            outfile.open(ClassArray::output, std::ios_base::app);
            outfile<<pString[i]<<"\n\n";
            if(x==1){
                outfile<<"Invalid Move!"<<"\n\n";     //writing in txt
            }
            outfile<<"****************************************"<<"\n\n";
            outfile.close();
            ClassFile::main(pString[i]);

        }
        else if (pString[i].find("open from stock") < pString[i].length()) {
            std::ofstream outfile;
            outfile.open(ClassArray::output, std::ios_base::app);
            outfile<<pString[i]<<"\n\n";
            outfile<<"****************************************"<<"\n\n";
            outfile.close();
            Class1::openstock();
            ClassFile::main(pString[i]);
        }

        else if (pString[i].find("open") < pString[i].length()) {
            removeDupWord(pString[i]);
            std::stringstream ss;
            ss << str1;
            int num;                  //converting int
            ss >> num;
            int x = Class1::open(num);
            std::ofstream outfile;
            outfile.open(ClassArray::output, std::ios_base::app);
            outfile<<pString[i]<<"\n\n";
            if(x==0){
                outfile<<"Invalid Move!"<<"\n\n";
            }
            outfile<<"****************************************"<<"\n\n";
            outfile.close();

            ClassFile::main(pString[i]);

        }
        else if(pString[i].find("move pile")<pString[i].length()){
            removeDupWord(pString[i]);
            std::stringstream ss;
            ss << arrayinsert[2];
            int num;
            ss >> num;
            std::stringstream ss1;
            ss1 << arrayinsert[3];
            int num1;
            ss1 >> num1;
            std::stringstream ss2;
            ss2 << arrayinsert[4];              //all of line for converting from string to int
            int num2;
            ss2 >> num2;
            std::ofstream outfile;
            outfile.open(ClassArray::output, std::ios_base::app);
            int x = Class1::movepile(num,num1,num2);

            outfile<<pString[i]<<"\n\n";
            if(x==0){
                outfile<<"Invalid Move!"<<"\n\n";   //for invalid move
            }
            outfile<<"****************************************"<<"\n\n";
            outfile.close();

            ClassFile::main(pString[i]);

        }
        else if(pString[i].find("exit")<pString[i].length()){        //for exit command
            std::ofstream outfile;
            outfile.open(ClassArray::output, std::ios_base::app);
            string x = Class1::exit();
            outfile<<pString[i]<<"\n\n";
            outfile<<"****************************************"<<"\n\n";
            outfile<<x;
            outfile.close();
            break;
        }
        else if(pString[i].find("move foundation pile")<pString[i].length()){
            removeDupWord(pString[i]);
            std::stringstream ss;
            ss << arrayinsert[2];
            int num;
            ss >> num;
            std::stringstream ss1;         //converting int like move foundation pile
            ss1 << arrayinsert[3];
            int num1;
            ss1 >> num1;
            std::ofstream outfile;
            outfile.open(ClassArray::output, std::ios_base::app);
            int x = Class1::movefoundation(num,num1);
            outfile<<pString[i]<<"\n\n";
            if(x==0){
                outfile<<"Invalid Move!"<<"\n\n";
            }
            outfile<<"****************************************"<<"\n\n";
            outfile.close();
            ClassFile::main(pString[i]);

        }
        else if(i == length-1){              //when finishing command line
            std::ofstream outfile;
            outfile.open(ClassArray::output, std::ios_base::app);
            outfile<< "exit"<<"\n\n";
            outfile<<"****************************************"<<"\n\n";
            for(int j=0;j<14;j++){
                if(ClassArray::array2[1][13]!="NULL" && ClassArray::array2[2][13]!="NULL" &&
                ClassArray::array2[3][13]!="NULL" && ClassArray::array2[4][13]!="NULL"){
                    outfile<< "Game Over!"<<"\n\n";
                    outfile<<"You Win!";
                    break;
                }
                else{
                    outfile<< "Game Over!"<<"\n\n";
                    break;

                }

            }
            outfile.close();
        }

    }
}

int Class2::main() {
    return 0;
}


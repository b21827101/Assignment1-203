//
// Created by EA on 14.11.2020.
//

#include <iostream>
#include <fstream>
#include "ClassFile.h"
#include "ClassArray.h"
#include "Class1.h"
using namespace std;

void ClassFile::creating(){
    ofstream MyFile(ClassArray::output);      //creating output txt
    MyFile.close();

}

void ClassFile::header(string intro){
    std::ofstream outfile;
    outfile.open(ClassArray::output, std::ios_base::app); // append instead of overwrite
    if(Class1::stockarray[0]!=0 && Class1::stockarray[1]!=0 && Class1::stockarray[2]!=0){
        outfile<<"@@@ ";

    }
    else{
        outfile<<"___ ";
    }
                                //piece of output pattern
    for(int i=0;i<3;i++){
        if(Class1::stockarray[i]!=0 && ClassArray::arrayyedek[0][Class1::stockarray[i]]!="NULL"){
            outfile<<ClassArray::arrayyedek[0][Class1::stockarray[i]];
        }
        else{
            outfile<<"___";
        }
        outfile<<" ";
    }
    outfile << "        ";
    for(int i = 1 ; i<5;i++){
        for(int j = 23 ; j >0 ;j--){
            if(ClassArray::array2[i][j] == "NULL" && j==1){
                outfile<<"___";                              //pile pattern
                break;
            }
            else if(ClassArray::array2[i][j] != "NULL"){
                outfile<<ClassArray::array2[i][j];
                break;
            }
        }
        outfile << " ";
    }
    outfile << "\n";
    outfile.close();

}



int ClassFile::main(string intro) {
    // Create and open a text file
    std::ofstream outfile;
    outfile.open(ClassArray::output, std::ios_base::app); // append instead of overwrite//
    header(intro);
    outfile<<"\n";
    int index5[7];
    for(int i = 5 ; i<12;i++){
        for(int j = 0 ; j<24;j++){
            if(ClassArray::arrayyedek[i][j] == "NULL"){
                index5[i-5]= j;           //taking column size for each column
                break;
            }
        }
    }
    for(int j = 1;j < 7; ++j){
        // Change < to > if you want to find the smallest element
        if(index5[j]>index5[0]  ){
            index5[0] = index5[j];                   //for fixing size of row
        }
    }

    for(int j = 0 ; j<index5[0];j++){
        for(int i = 5 ; i<12;i++){
            if(ClassArray::arrayyedek[i][j] != "NULL"){        //pile pattern
                outfile<<ClassArray::arrayyedek[i][j]<< "   ";
            }
            else{
                outfile<<"      ";
            }
        }
        outfile << "\n";
    }
    outfile<<endl;
    outfile.close();

}


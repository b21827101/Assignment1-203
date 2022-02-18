//
// Created by EA on 10.11.2020.
//
#include "ClassArray.h"
#include "Class1.h"
#include "Class2.h"
#include <string>
#include <iostream>
#include <sstream>


using namespace std;
int Class1::sayac =2 ;
int Class1::sayim=0;
int num3=0;
int Class1::stockarray[3];



int Class1::open(int pile_num){ //for open method
    for(int i = 0 ;i<24;i++){
        if(ClassArray::array2[pile_num+5][i] == "NULL") {
            if(i==0){
                ClassArray::arrayyedek[pile_num+5][i] = ClassArray::array2[pile_num+5][i];
                break;
            }
            else if(ClassArray::arrayyedek[pile_num+5][i-1] == ClassArray::array2[pile_num+5][i-1]){//won't open if it's already opened
                return 0;
            }
            else{
                ClassArray::arrayyedek[pile_num+5][i-1] = ClassArray::array2[pile_num+5][i-1];
                break;
            }
        }
    }
}

int Class1::movepile(int source_pile_num, int source_pile_card_index, int destination_num) {
    int length = sizeof(ClassArray::array2[destination_num + 5]) / sizeof(ClassArray::array2[destination_num + 5][0]);
    int index1;
    for (int i = 0; i < 24; i++) {
        if (ClassArray::arrayyedek[source_pile_num + 5][i] == "NULL") {//gets the index of the blank line
            index1 = i - 1;
            break;
        }
    }
    for (int i = index1 - source_pile_card_index; i < index1 + 1; i++) {
        char str1 = ClassArray::arrayyedek[source_pile_num + 5][i].at(0);
        string r = ClassArray::arrayyedek[source_pile_num + 5][i].substr(1, 2);
        std::stringstream ss1;
        ss1 << r;
        int num;
        ss1 >> num;
        for (int j = 0; j < 24; j++) {
            if (ClassArray::array2[destination_num + 5][j] == "NULL") {
                if(j==0 && num !=13 ){
                    return 0;
                    break;
                }
                else if(j==0 && num ==13 ){//if index is 0 and card ends with 13,statement is true
                    ClassArray::array2[destination_num + 5][j] = ClassArray::array2[source_pile_num + 5][i];
                    ClassArray::arrayyedek[destination_num + 5][j] = ClassArray::array2[source_pile_num + 5][i];
                    ClassArray::array2[source_pile_num + 5][i] = "NULL";
                    ClassArray::arrayyedek[source_pile_num + 5][i] = "NULL";
                    break;
                }
                else{
                    char str2 = ClassArray::arrayyedek[destination_num + 5][j - 1].at(0);
                    string r1 = ClassArray::arrayyedek[destination_num + 5][j - 1].substr(1, 2);
                    std::stringstream ss1;
                    ss1 << r1;
                    int num1;
                    ss1 >> num1;
                    //I took care of the exception here.
                    if((str1 == 'H' && (str1 != str2 && str2 != 'D' && (num + 1 == num1 || r1 == "UL")) ||(j == 0 && num == 13))
                       || (str1 == 'D' && (str1 != str2 && str2 != 'H' && (num + 1 == num1 || r1 == "UL")) || (j == 0 && num == 13))
                       || (str1 == 'S' && (str1 != str2 && str2 != 'C' && (num + 1 == num1 || r1 == "UL")) || (j == 0 && num == 13))
                       || (str1 == 'C' && str1 != str2 && str2 != 'S' && (num + 1 == num1 || r1 == "UL")) ||(j == 0 && num == 13)) {
                        ClassArray::array2[destination_num + 5][j] = ClassArray::array2[source_pile_num + 5][i];
                        ClassArray::arrayyedek[destination_num + 5][j] = ClassArray::array2[source_pile_num + 5][i];
                        ClassArray::array2[source_pile_num + 5][i] = "NULL";
                        ClassArray::arrayyedek[source_pile_num + 5][i] = "NULL";
                        break;
                    }
                    else {
                        return 0; //if it is invalid move
                        break;
                    }
                }

            }
        }
    }
}

int Class1::movemethod(int x,int numsub,string str1 ,int pilenum,int index1){//for move to foundation method
    for (int i = 0; i < 24; i++) {
        if (ClassArray::array2[x][i] == "NULL") {//gets the index of the blank line
            if(i==1 && numsub==1){
                ClassArray::array2[x][i] = str1;
                ClassArray::arrayyedek[x][i] = str1;
                ClassArray::arrayyedek[pilenum + 5][index1] = "NULL";
                ClassArray::array2[pilenum + 5][index1] = "NULL";
                break;
            }
            else if(i==1 && numsub!=1){//invalid move
                return 1;
                break;
            }
            else {
                string sub1 =  ClassArray::array2[x][i-1].substr(1,2);//taking int of card
                std::stringstream ss1;
                ss1 << sub1;
                int numsub1;
                ss1 >> numsub1;
                if(numsub1 +1 == numsub){     //if the card we appended is bigger
                    ClassArray::array2[x][i] = str1;
                    ClassArray::arrayyedek[x][i] = str1;
                    ClassArray::arrayyedek[pilenum + 5][index1] = "NULL";
                    ClassArray::array2[pilenum + 5][index1] = "NULL";
                    break;
                }
                else{
                    return 1;
                    break;
                }
            }
        }
    }
}

int Class1::movetofpile(int pilenum){
    string str1;
    int index1;
    for(int j=0;j<24;j++){
        if(ClassArray::array2[pilenum+5][j] == "NULL"){//gets the index of the blank line
            str1 = ClassArray::array2[pilenum+5][j-1];
            index1 = j-1;
            break;
        }
    }
    string sub =str1.substr(1,2);
    std::stringstream ss;
    ss << sub;
    int numsub;
    ss >> numsub;
    if(str1.rfind('H') < str1.length()) {//if car startswith H
        return movemethod(1,numsub, str1 , pilenum, index1);
    }
    else if(str1.rfind('D')< str1.length()) {//if car startswith D
        return movemethod(2,numsub, str1 , pilenum, index1);
    }
    else if(str1.rfind('S')< str1.length()) {//if car startswith S
        return movemethod(3,numsub, str1 , pilenum, index1);
    }

    else if(str1.rfind('C')< str1.length()){
        //if car startswith C
       return movemethod(4,numsub, str1 , pilenum, index1);

    }
}


int Class1::movewaste(int destinationnum) { //for move waste
    int length = sizeof(ClassArray::array2[destinationnum + 5]) / sizeof(ClassArray::array2[destinationnum + 5][0]);
    for (int j = 0; j < length; j++) {
        if (ClassArray::array2[destinationnum + 5][j] == "NULL") {
            string r2 = ClassArray::arrayyedek[0][stockarray[sayac]].substr(1, 2);
            if (j == 0 && r2 == "13") {  //if index is zero and ends with 13
                ClassArray::array2[destinationnum + 5][j] = ClassArray::array2[0][stockarray[sayac]];
                ClassArray::arrayyedek[destinationnum + 5][j] = ClassArray::array2[0][stockarray[sayac]];
                ClassArray::arrayyedek[0][stockarray[sayac]] = "NULL";
                ClassArray::array2[0][stockarray[sayac]] = "NULL";
                sayac--;
                break;
            } else if (j == 0 && r2 != "13") {
                return 1; //invalid move
                break;
            }
            else {
                char str1 = ClassArray::array2[destinationnum + 5][j - 1].at(0);  //taking previous index for valid move
                char str2 = ClassArray::arrayyedek[0][stockarray[sayac]].at(0);
                string r1 = ClassArray::array2[destinationnum + 5][j - 1].substr(1, 2);
                std::stringstream ss;
                ss << r1;
                int num1;
                ss >> num1;
                std::stringstream ss1;
                ss1 << r2;
                int num2;
                ss1 >> num2;
                if ((str1 == 'H' && str1 != str2 && str2 != 'D' && num2 + 1 == num1) ||    //compare to exception
                    (str1 == 'D' && str1 != str2 && str2 != 'H' && num2 + 1 == num1) ||
                    (str1 == 'S' && str1 != str2 && str2 != 'C' && num2 + 1 == num1) ||
                    (str1 == 'C' && str1 != str2 && str2 != 'S' && num2 + 1 == num1)) {
                    ClassArray::array2[destinationnum + 5][j] = ClassArray::array2[0][stockarray[sayac]];
                    ClassArray::arrayyedek[destinationnum + 5][j] = ClassArray::array2[0][stockarray[sayac]];
                    ClassArray::arrayyedek[0][stockarray[sayac]] = "NULL";
                    ClassArray::array2[0][stockarray[sayac]] = "NULL";
                    sayac--;
                    break;

                }
                else if((!(str1 == 'H' && str1 != str2 && str2 != 'D' && num2 + 1 == num1) ||
                           !(str1 == 'D' && str1 != str2 && str2 != 'H' && num2 + 1 == num1) ||
                           !(str1 == 'S' && str1 != str2 && str2 != 'C' && num2 + 1 == num1) ||
                           !(str1 == 'C' && str1 != str2 && str2 != 'S' && num2 + 1 == num1))) {
                    return 1;
                    break;
                }
        }

        }
    }
}


void Class1::numberstock(){
    num3=0;
    sayim=0;

}

void Class1::openstock(){  //for openstock
    string x;
    sayim =0;
    sayac = 2;
    for(int i =0;i<3;i++){
        stockarray[i]=0;
    }
    while(sayim<3){  //for taking three elements of array
        if(num3 == 24){
            sayim=3;
            num3=0;
            continue;
        }
        if(num3 == 24){
            num3 = 0;
            sayac = 2;
            sayim =0;

            x="___ ___ ___";
            break;
        }
        if(ClassArray::arrayyedek[0][23-num3] != "NULL"){//if it is not null,should writing this element
            x +=" "+ClassArray::arrayyedek[0][23-num3];
            stockarray[sayim] = 23-num3;
            sayim=sayim+1;


        }
        num3=num3+1;
    }
}


int Class1::movetofoundationwaste() { //for move to foundation waste
    string waste = ClassArray::arrayyedek[0][stockarray[sayac]];
    string waste1 = ClassArray::arrayyedek[0][stockarray[sayac]].substr(1,2);
    std::stringstream ss;
    ss << waste1;
    int num1;
    ss >> num1;
    if (waste.find("H") < waste.length()) { //if starts with H
        for (int i = 0; i <24; i++) {
            if (ClassArray::array2[1][i] == "NULL") {
                if(i==1 && waste.substr(1,2)=="01"){
                    ClassArray::array2[1][i] = waste;
                    ClassArray::arrayyedek[0][stockarray[sayac]] = "NULL";
                    ClassArray::array2[0][stockarray[sayac]] = "NULL";
                    sayac--;
                    break;
                }
                else if(i==1 && waste.substr(1,2) !="01"){
                    return 1;     //can't append the element
                    break;
                }
                else{
                    string str1 = ClassArray::array2[1][i-1].substr(1,2);
                    std::stringstream ss1;
                    ss1 << str1;
                    int num2;
                    ss1 >> num2;
                    if(num2+1==num1){
                        ClassArray::array2[1][i] = waste;          //implement the element
                        ClassArray::arrayyedek[0][stockarray[sayac]] = "NULL";
                        ClassArray::array2[0][stockarray[sayac]] = "NULL";
                        sayac--;
                        break;
                    }
                    else{
                        return 1;
                        break;     //invalid move
                    }
                }

            }
        }

    }

    else if(waste.find('D')< waste.length()){   //if starts with D
        for (int i = 0; i <24; i++) {
            if (ClassArray::array2[2][i] == "NULL") {
                if(i==1 && waste.substr(1,2)=="01"){
                    ClassArray::array2[2][i] = waste;
                    ClassArray::arrayyedek[0][stockarray[sayac]] = "NULL";
                    ClassArray::array2[0][stockarray[sayac]] = "NULL";
                    sayac--;
                    break;
                }
                else if(i==1 && waste.substr(1,2) !="01"){
                    break;        //in 0.index,cant be 01
                    return 1;

                }
                else{
                    string str1 = ClassArray::array2[2][i-1].substr(1,2);
                    std::stringstream ss1;
                    ss1 << str1;
                    int num2;
                    ss1 >> num2;
                    if(num2+1==num1){
                        ClassArray::array2[2][i] = waste;  //implement the element if is valid
                        ClassArray::arrayyedek[0][stockarray[sayac]] = "NULL";
                        ClassArray::array2[0][stockarray[sayac]] = "NULL";
                        sayac--;
                        break;
                    }
                    else{
                        break;
                        return 1;

                    }
                }
            }
        }
    }
    else if(waste.find('S')< waste.length()){//if starts with S
        for (int i = 0; i <24; i++) {
            if (ClassArray::array2[3][i] == "NULL") {
                if(i==1 && waste.substr(1,2)=="01"){
                    ClassArray::array2[3][i] = waste;
                    ClassArray::arrayyedek[0][stockarray[sayac]] = "NULL";
                    ClassArray::array2[0][stockarray[sayac]] = "NULL";
                    sayac--;
                    break;
                }
                else if(i==1 && waste.substr(1,2) !="01"){
                    break;
                    return 1;
                }
                else{
                    string str1 = ClassArray::array2[3][i-1].substr(1,2);  //substring for compare invalid situations
                    std::stringstream ss1;
                    ss1 << str1;
                    int num2;
                    ss1 >> num2;
                    if(num2+1==num1){
                        ClassArray::array2[3][i] = waste;
                        ClassArray::arrayyedek[0][stockarray[sayac]] = "NULL";
                        ClassArray::array2[0][stockarray[sayac]] = "NULL";
                        sayac--;
                        break;
                    }
                    else{
                        break;
                        return 1;    //can't append the element
                    }
                }

            }
        }
    }
    else if(waste.find('C')< waste.length()){   //if starts with C
        for (int i = 0; i <24; i++) {
            if (ClassArray::array2[4][i] == "NULL") {
                if(i==1 && waste.substr(1,2)=="01"){
                    ClassArray::array2[4][i] = waste;
                    ClassArray::arrayyedek[0][stockarray[sayac]] = "NULL";
                    ClassArray::array2[0][stockarray[sayac]] = "NULL";
                    sayac--;
                    break;

                }
                else if(i==1 && waste.substr(1,2) !="01"){
                    break;
                    return 1;
                }
                else{
                    string str1 = ClassArray::array2[4][i-1].substr(1,2);//substring for compare invalid situations
                    std::stringstream ss1;
                    ss1 << str1;
                    int num2;
                    ss1 >> num2;
                    if(num2+1==num1){
                        ClassArray::array2[4][i] = waste;
                        ClassArray::arrayyedek[0][stockarray[sayac]] = "NULL";
                        ClassArray::array2[0][stockarray[sayac]] = "NULL";

                        sayac--;
                        break;
                    }
                    else{
                        break;
                        return 1;
                    }
                }

            }
        }
    }
}


int Class1::movefoundation(int sourcefnum,int desninationnum){  //for move foundation method
    string str3;
    for(int i=0;i<24;i++){
        if(ClassArray::arrayyedek[desninationnum+5][i]=="NULL"){
            str3 =ClassArray::arrayyedek[desninationnum+5][i-1];   //taking biggest element in there
            break;
        }
    }
    string sub3 =str3.substr(1,2);
    std::stringstream ss; //converting int
    ss << sub3;
    int num1;
    ss >> num1;
    for(int i=0;i<24;i++){
        if(ClassArray::array2[sourcefnum+1][i]=="NULL"){
            if(i==1){
                return 0;
                break;
            }
            else {
                char at3 =str3.at(0);
                char at4 = ClassArray::array2[sourcefnum+1][i-1].at(0);
                string str4 =ClassArray::array2[sourcefnum+1][i-1].substr(1,2);
                std::stringstream ss1;
                ss1 << str4;
                int num2;
                ss1 >> num2;
                if((at3 == 'H' && at3 != at4 && at4 != 'D' && num2 + 1 == num1) ||
                   (at3 == 'D' && at3 != at4 && at4 != 'H' && num2 + 1 == num1) ||   //exception
                   (at3 == 'S' && at3 != at4 && at4 != 'C' && num2 + 1 == num1) ||
                   (at3 == 'C' && at3 != at4 && at4 != 'S' && num2 + 1 == num1)) {
                    ClassArray::arrayyedek[desninationnum+5][i] = ClassArray::array2[sourcefnum+1][i-1];
                    ClassArray::array2[sourcefnum+1][i-1] = "NULL";   //deleting the element from the array
                    break;
                }
                else{
                    break;
                }
            }
        }

    }
}

int Class1::main() {
    return 0;
}


string Class1::exit() {  //for exit method
    for(int i =1 ;i<5 ;i++){
        for(int j=0;j<14;j++){
            if(ClassArray::array2[i][j]=="NULL"){  //if it is not full
                return "Game Over!";
            }
        }
    }
    return "You Win!";
}










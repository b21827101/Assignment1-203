#include <cstring>
#include "ClassArray.h"
#include "Class1.h"
#include "Class2.h"
#include "ClassFile.h"
using namespace std;


int main(int argc, char** argv) {
        strcpy (ClassArray::deck,argv[1]);
        strcpy (ClassArray::commands,argv[2]);
        strcpy (ClassArray::output,argv[3]);

    ClassArray::main();
    Class1::main();
    Class2::main();
    return 0;
}
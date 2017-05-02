#include <iostream>
#include "pfraction.h"
using namespace std;

int main(/*int argc, char *argv[]*/)
{
    PFraction f1(-8);
    PFraction f2(2,3);
    cout << "Hello World!" << endl << f1-f2 << endl << f2+f1;
    return 0;
}

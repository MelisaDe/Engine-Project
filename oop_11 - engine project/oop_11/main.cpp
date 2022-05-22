#include <iostream>
#include "Control.h"


using namespace std;
///The users will provide an input and output file from the command line ,created objects and called the required funcitons.
int main(int argc, char** argv) {
    //argc is number of parameters.
    // argv is string array of parameters provided by user.
    Control c;

    if (argc == 1) {
        cout << "Please provide the command line arguments" << endl;
        return 0;
    }

    //argv[1] and argv[2] are sent as a parameter to the function that take the file name 
    c.GetFileName(argv[1], argv[2]);

    return 0;
}
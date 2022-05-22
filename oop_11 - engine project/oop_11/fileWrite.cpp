#include <iostream>
#include <string>
#include <fstream>
#include "fileWrite.h"

using namespace std;
fileWrite w;//extern type object.
// function to create output file.
void fileWrite::createfile(string argv2) {
	output.open(argv2); //open output file
	if (!output)
	{
		cout << "ERROR!File is not open. " << endl;
		exit(0);
	}
}
//function to write command to output file.(overloading)
void fileWrite::writeCommand(string s) {
	output << s; //write to output file
}
//function to write command to output file.(overloading)
void fileWrite::writeCommand(double s) {
	output << s; //write to output file
}
//function to close output file
void fileWrite::closefile() {
	output.close(); //close output file
}

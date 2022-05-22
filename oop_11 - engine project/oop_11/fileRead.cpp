#include <iostream>
#include <string>
#include <fstream>
#include "Control.h"
#include "fileRead.h"

using namespace std;

fileRead::fileRead() {

}
//function that reads the commands from the input file.
void fileRead::readCommand(char* argv) {
	Control cc;
	//opening the file
	fstream input(argv, ios::in);
	//control the opening of file
	if (!input)
	{
		cout << "ERROR!File is not found." << endl;
		exit(0);
	}
	string s = "";
	//getting commands from file until command is stop_simulation.
	while (s != "stop_simulation;")
	{
		getline(input, s);
		//commands sends as a parametres to arrangement and call the right function.
		cc.CallClassFunc(s);
	}
	input.close();
}



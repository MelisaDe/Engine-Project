#ifndef FÝLE_READ_H
#define FÝLE_READ_H
#include<string>
using namespace std;

///A class that reads the commands from the input file, calls the required classes and creates an output file
class fileRead {
public:
	fileRead();//constructor
	/** \brief function that reads the commands from the input file.
	  * \param argv is the char pointer to represent input file's name.
	 */
	void readCommand(char* argv);
};


#endif
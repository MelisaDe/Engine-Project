#ifndef FÝLE_WRÝTE_H
#define FÝLE_WRÝTE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

///A class that reads the commands from the input file, calls the required classes and creates an output file
class fileWrite {
private:
	ofstream output;
public:
	/** \brief function to create output file
	  * \param argv is the string argument to represent name of output.
	 */
	void createfile(string argv);
	/** \brief function to write command to output file.(overloading)
	  * \param s is the string argument to represent outputs.
	 */
	void writeCommand(string s);
	/** \brief function to write command to output file.(overloading)
	  * \param s is the string argument to represent outputs.
	 */
	void writeCommand(double s);
	///function to close output file
	void closefile();
};
extern fileWrite w;  /*!< w is created extern type object. */
#endif 
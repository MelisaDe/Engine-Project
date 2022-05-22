#ifndef CONTROL_H
#define CONTROL_H
#include<string>
#include "engine.h"
#include "tankList.h"
using namespace std;

///A class calls the required classes
class Control {
private:
	tankList l; //created object to use tankList class' functions and attributes.
	engine* e = engine::getInstance();//to use engine class functions.
public:
	Control();//constructor
	/** \brief get the file name and call the readComment function.
	  * \param avg1 is the first char pointer to represent input file's name.
	   * \param avg2 is the  second char pointer to represent output files's name.
	 */
	void GetFileName(char* avg1, char* avg2);
	/** \brief calls the required classes
	  * \param s is the string argument to represent commands.
	 */ 
	void CallClassFunc(string s);
	///function to stop simulation and making required operation before closing.
	void stop_simulation();
};
#endif
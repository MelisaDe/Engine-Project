#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"
#include<vector>

using namespace std;
///A abstract class to subject
class Subject
{
public:
    vector<Observer*> _observers; /*!< State to respresent simiulation stopped or not.*/
    /** \brief added tanks and valves to _observers vector.
	  * \param o is Observer* argument to represent tank or valve as observer .
	 */
     void Attach(Observer* o);
     /** \brief remove tanks and valves from _observers vector
	  * \param o is Observer* argument to represent tank or valve as observer .
	 */
     void Detach(Observer* o);
     /** \brief To notify state situation to observers. 
	 */
     void Notify();
     /** \brief pure virtual type function to set the state of engine.
	  * \param value is int argument to represent state.
	 */
    virtual void set_state(int value) = 0;
    /** \brief pure virtual type function to get the state of engine.
	 */
    virtual int get_state() = 0;
};

#endif
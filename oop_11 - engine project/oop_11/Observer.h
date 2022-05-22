#ifndef OBSERVER_H
#define  OBSERVER_H
using namespace std;

class Subject;
///A base class to observers.
class Observer
{
public:
    Subject* sub; /*!< sub subject tyoe object to respresent engine.*/
    /** \brief pure virtual type function to update tanks' and valves' state situation's update.
	 */
    virtual void Update() = 0;
};

#endif
#ifndef VALVE_H
#define VALVE_H
#include "Observer.h"
#include "Subject.h"

using namespace std;
///A class to valve condition.
class Valve :public Observer{
private:
	bool valve;/*!< valve is a bool type variable which take valve's open or close situation */
	int valve_id;/*!< valve_id is a int type variable which take valve's id */
	static int assigned_valve_id;/*!< assigned_valve_id is a static int type variable which using for assign new valve's id. */
	int state;/*!< State to respresent simiulation stopped or not.*/
public:
	Valve();
	/** \brief subject's  new valve observers attached to observers vector.
	  * \param obj is Subject argument to represent engine as subject .
	 */
	void valveset(Subject* obj);
	///valve observer's state situations updated.
	void Update();
	///@param valve_ to represent to valve
	void set_valve(bool valve_);
	///@return valve
	bool get_valve();
	///@return valve_id
	int get_valve_id();
};
#endif;

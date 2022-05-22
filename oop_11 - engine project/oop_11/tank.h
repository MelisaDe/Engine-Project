#ifndef TANK_H
#define TANK_H
#include "Observer.h"
#include "Subject.h"

/// A Class to keep tanks' information.
class tank:public Observer {
private:
	double capacity;/*!< capacity is a double type variable which take tank's maximum capacity*/
	double fuel_quantity;/*!< fuel_quantity is a double type variable which take tank's fuel quantity */
	bool broken;/*!< broken is a bool type variable which represent to tank is broken or not.  */
	int id;/*!< id is a int type variable which is tank's id.*/
	static int assigned_id;/*!< assigned_id is a static int type variable to get current id.*/
	int state;/*!< State to respresent simiulation stopped or not.*/
public:
	
	/** \brief subject's new  tank observers attached to observers vector.
	  * \param obj is Subject argument to represent engine as subject .
	 */
	void tankset(Subject* obj);
	///tank observer's state situations updated.
	void Update();
	/// @param capacity is the double argument to represent capacity of tank.
	tank(double capacity);//constructor
	tank();
	~tank();//destructor
	/// @param capacity_ is the double argument to represent capacity of tank.
	void set_capacity(double capacity_);
	/// @return capacity
	double get_capacity();
	/// @return id
	int get_id();
	/// @param fuel_quantity_ is double argument to represent quantity of tank.
	void set_fuel_quantity(double fuel_quantity_);
	/// @return fuel quantity
	double get_fuel_quantity();
	/// @param broken_ is bool argument to represent broken situation.
	void set_broken(bool broken_);
	/// @return broke situation
	bool get_broken();
};

#endif
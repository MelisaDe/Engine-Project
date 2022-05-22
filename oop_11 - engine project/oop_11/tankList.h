#ifndef TANKLIST_H
#define TANKLIST_H
#include<vector>
#include"tank.h"
#include"Valve.h"
#include"Observer.h"
#include"Subject.h"
///A class to make Tanks' operations.
class tankList{
private:
	std::vector<tank> Tanks; /*!< Tanks is created using vector. */
	std::vector<Valve> Valves;/*!< Valves is created using vector. */
public:
	/** \brief function for adding new tanks.
	  * \param capacity_ is double argument to represent capacity of tank.
	 */
	void add_fuel_tank(double capacity_);
	///function to list fuel tanks.
	void list_fuel_tanks();
	/** \brief function to remove tanks.
	  * \param tank_id is int argument to represent id of tank.
	 */
	void remove_fuel_tank(int tank_id);
	/** \brief function to connecting tanks to engine.
	  * \param tank_id is int argument to represent id of tank.
	 */
	void connect_fuel_tank_to_engine(int tank_id);
	/** \brief function to disconnecting tanks from engine.
	  * \param tank_id is int argument to represent id of tank.
	 */
	void disconnect_fuel_tank_from_engine(int tank_id);
	/** \brief function to open tank's valve.
	  * \param tank_id is int argument to represent id of tank.
	 */
	void open_valve(int tank_id);
	/** \brief function to close tank's valve.
	  * \param tank_id is int argument to represent id of tank.
	 */
	void close_valve(int tank_id);
	/** \brief function to break tanks.
	  * \param tank_id is int argument to represent id of tank.
	 */
	void break_fuel_tank(int tank_id);
	/** \brief function to repair tanks.
	  * \param tank_id is int argument to represent id of tank.
	 */
	void repair_fuel_tank(int tank_id);
	///function to print fuel_tank_count.
	void print_fuel_tank_count();
	/** \brief function to print tank into
	  * \param tank_id is int argument to represent id of tank.
	 */
	void print_tank_info(int tank_id);
	/** \brief function to fill given tank
	  * \param tank_id is int argument to represent id of tank.
	  * \param fuel_quantity is double argument to represent fuel quantity of tank.
	 */
	void fill_tank(int tank_id, double fuel_quantity);
};

extern Subject* obj; /*!< obj is created extern type Subject object. */
#endif;
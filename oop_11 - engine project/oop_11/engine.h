#ifndef ENGÝNE_H
#define ENGÝNE_H
#include<vector>
#include "tank.h"
#include"Valve.h"
#include"Subject.h"

///singleton pattern used to only one engine class.
class engine: public Subject {
private:
	int state;/*!< State to respresent simiulation stopped or not.*/
	tank internalTank; /*!< internal tank is created. */
	const double fuel_per_second = 5.5;/*!< engine consumed 5.5 fuel per second.*/
	bool status; /*!< bool variable to respresent engine's working situation*/
	static engine* instance;  /*!< here will be the instance stored */
	engine(const engine&) = delete;///to avoid copy the class copy constructor deleted.
	engine& operator=(const engine&) = delete;///copy constructor deleted.
	///private constructor to prevent instancing.
	engine();
	~engine();//destructor
public:
	std::vector<tank> Connected_Tanks; /*!< Connected Tanks is created using vector. */
	std::vector<Valve> Connected_Valves;/*!< Connected Valves is created using vector. */
	///@param value to represent state
	void set_state(int value);
	/// @return state.
	int get_state();
	
	double consumed_fuel_quantity = 0; /*!< consumed fuel quantity is 0 at first.*/
	double total_fuel_quantity = 55; /*!< total fuel quantity is 55 at first.*/
	/// function for list connected tanks' infos to output file.
	void list_connected_tanks();
	/// function for print total consumed fuel quantity to output file.
	void print_total_consumed_fuel_quantity();
	/// function for print total fuel quantity to output file.
	void print_total_fuel_quantity();
	static engine* getInstance();//static access method.
	static void ResetInstance();//instance deleted to avoid memory leak.
	/// @return fuel_per_second.
	double get_fuel();
	/** \brief checking and if engine is working ,fuel is consumed..
	  * \param sec is int argument to represent how many second is spend.
	 */
	void check_internal(int sec);
	/// @return status.
	bool get_status();
	///if engine has connected tank, engine is start working.
	void start_engine();
	///engine is stop working and engine's status changing to false.
	void stop_engine();
	/** \brief engine's internal tank give its fuel to connected tanks randomly.
	  * \param quantity is double argument.
	 */
	void give_back_fuel(double quantity);
};

#endif
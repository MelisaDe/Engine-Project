#include <iostream>
#include<vector>
#include "engine.h"
#include"fileWrite.h"

using namespace std;
engine* engine::instance = 0;//null,because instance will be initialized on demand.

/// In this funtion ,if instance is created already returns available instance.if instance is not created before new instance will created.
///@returns instance
engine* engine::getInstance() {
	if (instance == 0) {
		instance = new engine();
	}
	return instance;
}
/// In this function ,to avoid memory leak instance is deleted.
void engine::ResetInstance()
{
	delete instance; // it works even if the pointer is NULL (does nothing then)
	instance = NULL; // so GetInstance will still work.
}
engine::engine() {
	status = 0;
	internalTank.set_fuel_quantity(55);
	internalTank.set_capacity(55);
}
engine::~engine() {

}
double engine::get_fuel() {
	return fuel_per_second;
}
bool engine::get_status() {
	return status;
}
//if engine has connected tank, engine is start working.
void engine::start_engine() {
	if (Connected_Tanks.size() > 0) //if connected tanks' size is more than 0, engine is start.
	{
		status = true;
	}
	else //if connected tanks' size is less than 0, engine can not start.
	{
		w.writeCommand("ERROR!Engine can't start without any connected tanks.");
		w.writeCommand("\n");
	}
}
//engine is stop working and engine's status changing to false.
void engine::stop_engine() {
	status = false; // engine become close.
	int b;
	double min;
	// tank which has minimum fuel quantity is found 
	min = Connected_Tanks[0].get_fuel_quantity();
	for (int i = 0; i < Connected_Tanks.size(); i++)
	{
		min = Connected_Tanks[i].get_fuel_quantity() < min ? Connected_Tanks[i].get_fuel_quantity() : min;
	}
	for (int i = 0; i < Connected_Tanks.size(); i++) {
		if (min == Connected_Tanks[i].get_fuel_quantity()) {
			b = i;
			break;
		}
	}
	// fuel which is in the internal tank transfer to connected tank which has minimum fuel quantity.
	double a = internalTank.get_fuel_quantity();
	internalTank.set_fuel_quantity(0);
	Connected_Tanks[b].set_fuel_quantity(Connected_Tanks[b].get_fuel_quantity() + a);
}
//engine's internal tank give its fuel to connected tanks randomly.
void engine::give_back_fuel(double quantity) {
	int a;
	if (quantity <= internalTank.get_fuel_quantity()) //control the given quantity is less then internal tank's quantity.
	{
		for (int i = 0; i < Connected_Tanks.size(); i++)
		{
			a = i;
			if (quantity + Connected_Tanks[a].get_fuel_quantity() < Connected_Tanks[a].get_capacity()) {
				break;
			}
		}
		//fuel which is in the internal tank transfer to connected tank by choosing randomly.
		Connected_Tanks[a].set_fuel_quantity(Connected_Tanks[a].get_fuel_quantity() + quantity);
		internalTank.set_fuel_quantity(internalTank.get_fuel_quantity() - quantity);
	}
	else //if given quantity is more than internal tank's quantity,user warned.
	{
		w.writeCommand("ERROR! Entered quantity is more than internal tank's quantity.");
		w.writeCommand("\n");
	}
}
// function for list connected tanks' infos to output file.
void engine::list_connected_tanks() {
	for (int i = 0; i < Connected_Tanks.size(); i++)
	{
		w.writeCommand("Tank ");
		w.writeCommand(Connected_Tanks[i].get_id());
		w.writeCommand("\n");
		w.writeCommand("Tank Capacity ");
		w.writeCommand(Connected_Tanks[i].get_capacity());
		w.writeCommand("\n");
		w.writeCommand("Tank Quantity ");
		w.writeCommand(Connected_Tanks[i].get_fuel_quantity());
		w.writeCommand("\n");
		if (Connected_Tanks[i].get_broken())
		{
			w.writeCommand("Tank is broken.");
			w.writeCommand("\n");
		}
		else {
			w.writeCommand("Tank is not broken.");
			w.writeCommand("\n");
		}
		if (Connected_Valves[i].get_valve())
		{
			w.writeCommand("Tank valve is open.");
			w.writeCommand("\n");
		}
		else {
			w.writeCommand("Tank valve is close.");
			w.writeCommand("\n");
		}
	}
}
// function for print total consumed fuel quantity to output file.
void engine::print_total_consumed_fuel_quantity() {
	// print total consumed fuel quantity
	w.writeCommand("Total Consumed Fuel Quantity: ");
	w.writeCommand(consumed_fuel_quantity);
	w.writeCommand("\n");
}
// function for print total fuel quantity to output file.
void engine::print_total_fuel_quantity() {
	// print total fuel quantity.
	w.writeCommand("Total Fuel Quantity: ");
	w.writeCommand(total_fuel_quantity);
	w.writeCommand("\n");
}
//checking and if engine is working ,fuel is consumed.
void engine::check_internal(int sec) {
	int a;
	double x;
	int temp = 0;

	if (status == true) //if engine is working, control the situtations.
	{
		if (internalTank.get_fuel_quantity() < 20)//if internal tank's quantity is less than 20,control the connected tanks' situtaions.
		{
			for (int i = 0; i < Connected_Tanks.size(); i++)
			{
				//choosing connected tank randomly.
				a = i;
				x = Connected_Tanks[a].get_fuel_quantity();
				//check the chosen connected tank is  whether available or not.
				if (x > sec* (fuel_per_second) && !Connected_Tanks[a].get_broken() && Connected_Valves[a].get_valve()) {
					temp = 1;
					break;
				}
			}
			if (temp == 0) //if there is no wastable fuel quantity, engine will stop working.
			{
				w.writeCommand("There is no enough available fuel. Engine can not consumed fuel. Engine is stopped.");
				w.writeCommand("\n");
				stop_engine();
			}
			else //fuel quantity wasted from chosen wastable connected tank.
			{
				x = Connected_Tanks[a].get_fuel_quantity();
				Connected_Tanks[a].set_fuel_quantity(x - (sec * (fuel_per_second)));
				consumed_fuel_quantity += sec * fuel_per_second;
				total_fuel_quantity -= sec * fuel_per_second;
			}
		}
		else  //if internal tank's quantity is more than 20, fuel quantity wasted from internal tank.
		{
			x = internalTank.get_fuel_quantity();
			internalTank.set_fuel_quantity(x - sec * (fuel_per_second));
			consumed_fuel_quantity += sec * fuel_per_second;
			total_fuel_quantity -= sec * fuel_per_second;
		}
	}
}
void engine::set_state(int value) {
	state = value;
	if (state == 1) {
		w.writeCommand("Engine: Simulation stopped");
		w.writeCommand("\n");
	}
	Notify();//To notify  state situation  to observers. 
}
int engine::get_state() {
	return state;
}




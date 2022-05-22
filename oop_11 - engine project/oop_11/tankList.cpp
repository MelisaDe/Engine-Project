#include <iostream>
#include<vector>
#include "tankList.h"
#include "engine.h"
#include"fileWrite.h"

using namespace std;
Subject* obj;
//function for adding new tanks.
void tankList::add_fuel_tank(double capacity_) {
	engine* e = engine::getInstance();
	obj = e;//extern  engine  object assigned subject object.
	tank *t = new tank(capacity_);//create new tank
	t->tankset(obj);//subject's new  tank observers attached to observers vector.
	Observer* obj1 = t;//new tanks added as observer.
	Tanks.push_back(*t); //push new tank to Tanks
	Valve* va=new Valve();//create new valve
	va->valveset(obj);//subject's new  valve observers attached to observers vector.
	Observer* obj2 = va;//new valves addded as observer
	Valves.push_back(*va);//push new valve to Valves
}
//function to list fuel tanks.
void tankList::list_fuel_tanks() {
	//list fuel tanks 
	for (int i = 0; i < Tanks.size(); i++)
	{
		w.writeCommand("Tank ");
		w.writeCommand(Tanks[i].get_id());
		w.writeCommand("\n");
		w.writeCommand("Tank Capacity ");
		w.writeCommand(Tanks[i].get_capacity());
		w.writeCommand("\n");
		w.writeCommand("Tank Quantity ");
		w.writeCommand(Tanks[i].get_fuel_quantity());
		w.writeCommand("\n");
		if (Tanks[i].get_broken())
		{
			w.writeCommand("Tank is broken.");
			w.writeCommand("\n");
		}
		else {
			w.writeCommand("Tank is not broken.");
			w.writeCommand("\n");
		}
		if (Valves[i].get_valve())
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
//function to remove tanks.
void tankList::remove_fuel_tank(int tank_id) {
	engine* e = engine::getInstance();
	int temp = 0;
	for (int i = 0; i < Tanks.size(); i++)
	{
		if (Tanks[i].get_id() == tank_id) {
			Tanks.erase(Tanks.begin() + i); //remove from Tanks.
			Valves.erase(Valves.begin() + i);
			temp = 1;
			obj->Detach((obj->_observers[i*2+1]));
			obj->Detach((obj->_observers[i*2]));
		}
	}
	for (int i = 0; i < e->Connected_Tanks.size(); i++)
	{
		if (e->Connected_Tanks[i].get_id() == tank_id) {
			e->Connected_Tanks.erase(e->Connected_Tanks.begin() + i);//remove from Connected Tanks
			e->Connected_Valves.erase(e->Connected_Valves.begin() + i);
		}
	}
	if (temp == 0)//if there is no tank which has given id,user warned.
	{
		w.writeCommand("Tank is not found");
		w.writeCommand("\n");
	}


}
//function to connecting tanks to engine.
void tankList::connect_fuel_tank_to_engine(int tank_id) {
	engine* e = engine::getInstance();
	int temp = 0, temp2 = 0;

	for (int i = 0; i < e->Connected_Tanks.size(); i++)
	{
		if (e->Connected_Tanks[i].get_id() == tank_id)//control if the tanks is connected to engine already.
		{
			w.writeCommand("ERROR!This tank is already connected to engine.");
			w.writeCommand("\n");
			temp2 = 1;
			break;
		}
	}
	if (temp2 == 0)//if the tank is not connected to engine before.
	{
		for (int i = 0; i < Tanks.size(); i++)
		{
			if (Tanks[i].get_id() == tank_id && !Tanks[i].get_broken())
			{
				e->Connected_Tanks.push_back(Tanks[i]);//the tank is connected to engine.
				e->Connected_Valves.push_back(Valves[i]);
				temp = 1;
			}
		}
		if (temp == 0)//if there is no tank which has given id,user warned.
		{
			w.writeCommand("Tank is not found");
			w.writeCommand("\n");
		}
	}
}
//function to disconnecting tanks from engine.
void tankList::disconnect_fuel_tank_from_engine(int tank_id) {
	engine* e = engine::getInstance();
	int temp = 0;
	for (int i = 0; i < e->Connected_Tanks.size(); i++)
	{
		if (e->Connected_Tanks[i].get_id() == tank_id)//control there is any tank which has given id in the connected tanks.
		{
			e->Connected_Tanks.erase(e->Connected_Tanks.begin() + i); //if there is, tank is erased.
			e->Connected_Valves.erase(e->Connected_Valves.begin() + i);
			temp = 1;
		}
	}
	if (temp == 0) //if there is no tank which has given id,user warned.
	{
		w.writeCommand("Tank is not found");
		w.writeCommand("\n");
	}
}
//function to open tank's valve.
void tankList::open_valve(int tank_id) {
	engine* e = engine::getInstance();
	int temp = 0;
	for (int i = 0; i < Tanks.size(); i++) {
		if (Tanks[i].get_id() == tank_id) //control there is any tank which has given id in the Tanks.
		{
			temp = 1;
			Valves[i].set_valve(true); //if there is, tank's valve become open.
		}
	}
	if (temp == 0)//if there is no tank which has given id,user warned.
	{
		w.writeCommand("Tank is not found");
		w.writeCommand("\n");
	}
	for (int i = 0; i < e->Connected_Tanks.size(); i++)
	{
		if (e->Connected_Tanks[i].get_id() == tank_id)//control there is any tank which has given id in the connected tanks.
		{
			e->Connected_Valves[i].set_valve(true);  //if there is, tank's valve become open.
		}
	}

}
//function to close tank's valve.
void tankList::close_valve(int tank_id) {
	engine* e = engine::getInstance();
	int temp = 0;
	for (int i = 0; i < Tanks.size(); i++) {
		if (Tanks[i].get_id() == tank_id) //control there is any tank which has given id in the Tanks.
		{
			temp = 1;
			Valves[i].set_valve(false);//if there is, tank's valve become close.
		}
	}
	if (temp == 0)//if there is no tank which has given id,user warned.
	{
		w.writeCommand("Tank is not found");
		w.writeCommand("\n");
	}
	for (int i = 0; i < e->Connected_Tanks.size(); i++)
	{
		if (e->Connected_Tanks[i].get_id() == tank_id)//control there is any tank which has given id in the connected tanks.
		{
			e->Connected_Valves[i].set_valve(false);//if there is, tank's valve become close.
		}
	}
}
// function to break tanks.
void tankList::break_fuel_tank(int tank_id) {
	int temp = 0;
	for (int i = 0; i < Tanks.size(); i++) {
		if (Tanks[i].get_id() == tank_id) //control there is any tank which has given id in the Tanks.
		{
			temp = 1;
			Tanks[i].set_broken(true);//if there is, tank's broke situation become true.
		}
	}
	if (temp == 0)//if there is no tank which has given id,user warned.
	{
		w.writeCommand("Tank is not found");
		w.writeCommand("\n");
	}
}
// function to repair tanks.
void tankList::repair_fuel_tank(int tank_id) {
	int temp = 0;
	for (int i = 0; i < Tanks.size(); i++) {
		if (Tanks[i].get_id() == tank_id)//control there is any tank which has given id in the Tanks.
		{
			temp = 1;
			Tanks[i].set_broken(false);//if there is, tank's brkoe situation become false.
		}
	}
	if (temp == 0)//if there is no tank which has given id,user warned.
	{
		w.writeCommand("Tank is not found");
		w.writeCommand("\n");
	}
}
//function to print fuel_tank_count.
void tankList::print_fuel_tank_count() {
	//print fuel tank count
	w.writeCommand("Fuel Tank Count: ");
	w.writeCommand(Tanks.size());
	w.writeCommand("\n");
}
//function to print tank into
void tankList::print_tank_info(int tank_id) {
	//print tank's info
	int temp = 0;
	for (int i = 0; i < Tanks.size(); i++) {
		if (Tanks[i].get_id() == tank_id) {
			temp = 1;
			w.writeCommand("Tank ");
			w.writeCommand(Tanks[i].get_id());
			w.writeCommand("\n");
			w.writeCommand("Tank Capacity ");
			w.writeCommand(Tanks[i].get_capacity());
			w.writeCommand("\n");
			w.writeCommand("Tank Quantity ");
			w.writeCommand(Tanks[i].get_fuel_quantity());
			w.writeCommand("\n");
			if (Tanks[i].get_broken())
			{
				w.writeCommand("Tank is broken.");
				w.writeCommand("\n");
			}
			else {
				w.writeCommand("Tank is not broken.");
				w.writeCommand("\n");
			}
			if (Valves[i].get_valve())
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
	if (temp == 0) //if there is no tank which has given id,user warned.
	{
		w.writeCommand("Tank is not found");
	}
}
//function to fill given tank
void tankList::fill_tank(int tank_id, double fuel_quantity) {
	engine* e = engine::getInstance();
	int temp = 0;
	for (int i = 0; i < Tanks.size(); i++) {
		if (Tanks[i].get_id() == tank_id)//control there is any tank which has given id in the Tanks.
		{
			temp = 1;
			double a = Tanks[i].get_fuel_quantity();
			if ((a + fuel_quantity) > Tanks[i].get_capacity())//control new quantity is more than tank's capacity
			{
				w.writeCommand("ERROR!You cant fill fuel more than tank's capacity.");//if it is true, user warned.
				w.writeCommand("\n");
			}
			else //if new quantity is less than tank's capacity, new quantity assigned tank's quantity.
			{
				e->total_fuel_quantity += fuel_quantity;
				Tanks[i].set_fuel_quantity(a + fuel_quantity);
			}
		}
	}
	if (temp == 0)//if there is no tank which has given id,user warned.
	{
		w.writeCommand("Tank is not found");
		w.writeCommand("\n");
	}
}

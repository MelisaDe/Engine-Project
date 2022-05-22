#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include "fileRead.h"
#include"fileWrite.h"
#include "Control.h"
#include "engine.h"
#include "tankList.h"

using namespace std;

Control::Control() {

}
//get the file name and call the readComment function.
void Control::GetFileName(char* avg1, char* avg2) {
	fileRead f; //created object to use fileRead class' functions and attributes.
	w.createfile(avg2); //create output file using with extern type object.
	f.readCommand(avg1);//argv is sent as a parameter to the function that open file and reads the commands from file.
}
//function to stop simulation and making required operation before closing.
void Control::stop_simulation() {
	obj->set_state(1);
	w.closefile(); //output file is closed
	engine::ResetInstance();//to avoid memory leak delete function is called
	exit(0); //exit from simulation
}
//calls the right class function according to given commands.
void Control::CallClassFunc(string s) {
	string s1 = "", s2 = "", s3 = "";
	double a, b;
	int temp = 0, temp2 = 0, temp3 = 0;
	//separates command names and parametres.
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			temp = 1;
			i++;
			while (s[i] != ' ')
			{
				temp2 = 1;
				s2 += s[i];
				i++;
				if (s[i] == ';') {
					break;
				}
			}
			if (s[i] == ' ')
			{
				while (temp2 == 1)
				{
					s3 += s[i];
					i++;
					if (s[i] == ';') {
						break;
					}
				}
				temp2 = 2;
			}
		}
		if (temp == 0) {
			s1 += s[i];
		}
		if (s[i] == ';') {
			break;
		}
	}
	//string variables convert to double variables.
	if (temp == 1) {
		a = stod(s2);
	}
	//string variables convert to double variables. if command has 2 variables.
	if (temp2 == 2)
	{
		b = stod(s3);
	}
	//call the right class functions.
	if (s1 == "start_engine;")
	{
		e->check_internal(1);//checking and if engine is working ,fuel is consumed.
		e->start_engine();
	}
	else if (s1 == "stop_engine;")
	{
		e->check_internal(1);
		e->stop_engine();
	}
	else if (s1 == "give_back_fuel")
	{
		e->check_internal(1);
		e->give_back_fuel(a);
	}
	else if (s1 == "add_fuel_tank")
	{
		e->check_internal(1);
		l.add_fuel_tank(a);
	}
	else if (s1 == "list_fuel_tanks;")
	{
		e->check_internal(1);
		l.list_fuel_tanks();
	}
	else if (s1 == "remove_fuel_tank")
	{
		e->check_internal(1);
		l.remove_fuel_tank(a);
	}
	else if (s1 == "connect_fuel_tank_to_engine")
	{
		e->check_internal(1);
		l.connect_fuel_tank_to_engine(a);
	}
	else if (s1 == "disconnect_fuel_tank_from_engine")
	{
		e->check_internal(1);
		l.disconnect_fuel_tank_from_engine(a);
	}
	else if (s1 == "open_valve")
	{
		e->check_internal(1);
		l.open_valve(a);
	}
	else if (s1 == "close_valve")
	{
		e->check_internal(1);
		l.close_valve(a);
	}
	else if (s1 == "break_fuel_tank")
	{
		e->check_internal(1);
		l.break_fuel_tank(a);
	}
	else if (s1 == "repair_fuel_tank")
	{
		e->check_internal(1);
		l.repair_fuel_tank(a);
	}
	else if (s1 == "print_fuel_tank_count;")
	{
		e->check_internal(1);
		l.print_fuel_tank_count();
	}
	else if (s1 == "list_connected_tanks;")
	{
		e->check_internal(1);
		e->list_connected_tanks();
	}
	else if (s1 == "print_total_consumed_fuel_quantity;")
	{
		e->check_internal(1);
		e->print_total_consumed_fuel_quantity();
	}
	else if (s1 == "print_total_fuel_quantity;")
	{
		e->check_internal(1);
		e->print_total_fuel_quantity();
	}
	else if (s1 == "print_tank_info")
	{
		e->check_internal(1);
		l.print_tank_info(a);
	}
	else if (s1 == "fill_tank")
	{
		e->check_internal(1);
		l.fill_tank(a, b);
	}
	else if (s1 == "wait")
	{
		e->check_internal(a);
	}
	else if (s1 == "stop_simulation;")
	{
		e->check_internal(1);
		stop_simulation();
	}
	else {
		w.writeCommand("Command not found!");//if command is not correct, user is warned.
		w.writeCommand("\n");
	}
}
#include <iostream>
#include"Valve.h"
#include"fileWrite.h"

int Valve::assigned_valve_id = 1;
Valve::Valve() :valve_id(assigned_valve_id++) { valve = false; }
void Valve::set_valve(bool valve_) { valve = valve_; }
bool Valve::get_valve() { return valve; }
int Valve::get_valve_id() { return valve_id; }
//subject's new  valve observers attached to observers vector.
void Valve::valveset(Subject* obj)
{
	sub = obj;
	sub->Attach(this);
}
//valve observer's state situations updated.
void Valve:: Update() {
	w.writeCommand("Valve ");
	w.writeCommand(valve_id);
	w.writeCommand(": Simulation stopped.\n");
	state = sub->get_state();

}
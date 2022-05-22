#include <iostream>
#include "tank.h"
#include"fileWrite.h"

int tank::assigned_id = 1;

tank::tank(double capacity) : id(assigned_id++)  {
	this->capacity = capacity;//capacity is assigned by user.
	fuel_quantity = 0; //new created tank's first fuel quantity assigned 0.
	broken = false;  // new created tank's broke situation assigned not broken.
}
tank::tank() {

}
tank::~tank() {

}
void tank::set_capacity(double capacity_) {
	capacity = capacity_;
}
double tank::get_capacity() {
	return capacity;
}
void tank::set_fuel_quantity(double fuel_quantity_) {
	fuel_quantity = fuel_quantity_;
}
double tank::get_fuel_quantity()
{
	return fuel_quantity;
}
void tank::set_broken(bool broken_) {
	broken = broken_;
}
bool tank::get_broken() {
	return broken;
}
int tank::get_id() {
	return id;
}
//subject's new tank  observers attached to observers vector.
void tank::tankset(Subject* obj) {
	sub = obj;
	sub->Attach(this);
}
//tank observer's state situations updated.
void tank::Update() {
	w.writeCommand("Tank ");
	w.writeCommand(id);
	w.writeCommand(": Simulation stopped.\n");
	state = sub->get_state();
}


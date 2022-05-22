#include "Subject.h"
#include<vector>
#include<iostream>
#include<iterator>
using namespace std;
//added tanks and valves to _observers vector.
void Subject::Attach(Observer* o)
{
   _observers.push_back(o);
}
//remove tanks and valves from _observers vector
void Subject::Detach(Observer* o)
{
    int count = _observers.size();
    int i;

    for (i = 0; i < count; i++) {
        if (_observers[i] == o)
            break;
    }
    if (i < count)
        _observers.erase(_observers.begin() + i);
}
//To notify state situation to observers. 
void Subject::Notify()
{
    vector<Observer*>::iterator it = _observers.begin();
    while (it != _observers.end()) {
        (*it)->Update();
        ++it;
    }
  
}





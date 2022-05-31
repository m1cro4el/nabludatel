#pragma once
#include "Observer.h"
#include <iostream>
#include <list>
using namespace std;

class Subject
{
public:
	virtual void registerObserver(Observer* o) = 0;
	virtual void removeObserver(Observer* o) = 0;
	virtual void notifyObservers() = 0;
};


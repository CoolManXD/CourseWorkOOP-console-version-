#pragma once
#include <string>
#include "car.h"

class Driver {
private:
	std::string m_name;
	int m_yearExp;
	Car m_car;
public:
	Driver(std::string name = "undefined", int yearExp = 0, const Car &car = Car("undefined", "undefined", 0))
		: m_name(name), m_yearExp(yearExp), m_car(car)
	{
	}
	void getInfoDriver();
	~Driver() {}
};
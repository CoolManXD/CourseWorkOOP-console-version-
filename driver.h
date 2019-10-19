#pragma once
#include <string>
#include "car.h"

class Driver {
private:
	std::string m_name;
	int m_yearExp;
	Car m_car;
	bool m_isBusy{ false };
	float m_busyTime{ 0 };
public:
	Driver(std::string name = "undefined", int yearExp = 0, const Car& car = Car("undefined", "undefined", 0))
		: m_name(name), m_yearExp(yearExp), m_car(car)
	{
	}
	const std::string& getName();
	int getYearExp();
	Car& getCar();
	bool isBusy();
	~Driver() {}
	friend std::istream& operator>> (std::istream&, Driver&);
};

std::ostream& operator<< (std::ostream&, Driver&);
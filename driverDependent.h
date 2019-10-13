#pragma once
#include <string>
#include "car.h"

class DriverDependent {
private:
	std::string m_name;
	int m_yearExp;
	Car m_car;
	bool m_isBusy{ false };
	float m_busyTime{ 0 };
public:
	DriverDependent(std::string name = "undefined", int yearExp = 0, const Car &car = Car("undefined", "undefined", 0))
		: m_name(name), m_yearExp(yearExp), m_car(car)
	{
	}
	void getInfoDriver();
	std::string getName();
	int getYearExp();
	~DriverDependent() {}
};
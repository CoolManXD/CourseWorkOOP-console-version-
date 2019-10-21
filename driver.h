#pragma once
#include <string>
#include "car.h"

class DriverMap;

class Driver {
private:
	std::string m_name;
	int m_yearExp;
	Car m_car;
	bool m_isBusy{ false };
	float m_busyTime{ 0 };
	std::string m_location{ "1street" };
	static DriverMap* m_driverMap;
public:
	Driver(std::string name = "undefined", int yearExp = 0, const Car& car = Car("undefined", "undefined", false))
		:m_name{ name }, m_yearExp{ yearExp }, m_car{ car }
	{

	}
	const std::string& getName();
	int getYearExp();
	Car& getCar();
	bool isBusy();
	void changeIsBusy();
	const std::string& getLocation();
	void setLocation(const std::string&);

	float findWay(const std::string& from, const std::string& to);

	static void setDriverMap(DriverMap*);
	static DriverMap* getDriverMap();
	~Driver() {}
	friend std::istream& operator>> (std::istream&, Driver&);
};

std::ostream& operator<< (std::ostream&, Driver&);
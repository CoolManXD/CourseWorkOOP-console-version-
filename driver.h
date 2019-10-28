#pragma once
#include <string>
#include <chrono>
#include "taxiService.h"
#include "car.h"


class DriverMap;

class Driver: public TaxiService {
private:
	std::string m_name;
	int m_yearExp;
	Car m_car;
	bool m_isBusy{ false };
	double m_busyTime{ 0 };
	std::chrono::steady_clock::time_point m_startTime;
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
	double getBusyTime();
	std::chrono::steady_clock::time_point& getStartTime();

	static void setDriverMap(DriverMap*);
	static DriverMap* getDriverMap();

	virtual void changeIsBusy() override final;
	virtual void setTimeAttributes(double) override final;
	virtual const std::string& getLocation() override final;
	virtual void setLocation(const std::string&) override final;

	virtual float findWay(const std::string&, const std::string&) override final;

	virtual void calculatePrice(double) override {};
	virtual ~Driver() {}

	friend std::istream& operator>> (std::istream&, Driver&);
};

std::ostream& operator<< (std::ostream&, Driver&);
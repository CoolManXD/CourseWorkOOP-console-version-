#pragma once
#include <string>
#include "driver.h"

class DriverDependent {
private:
	Driver m_driver;
	float m_salary {10};
	static constexpr float m_percentageOfOrder = 0.25f;
public:
	DriverDependent(const Driver &driver = Driver("undefined", 0, Car("undefined", "undefined", 0)))
		: m_driver(driver)
	{
	}
	Driver& getDriver();
	void setSalary(float);
	float getSalary();
	static float getPercentageOfOrder();
	~DriverDependent() {}
	friend std::istream& operator>> (std::istream& in, DriverDependent&);
};

std::ostream& operator<< (std::ostream&, DriverDependent&);

float operator+(float money, DriverDependent& driver);
float operator+(DriverDependent& driver, float money);
float operator+=(float money, DriverDependent& driver);
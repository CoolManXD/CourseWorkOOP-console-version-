#pragma once
#include <string>
#include "driver.h"

class DriverIndependent {
private:
	Driver m_driver;
	float m_salary{ 0 };
	bool m_isCompanyInsured;
	bool m_isCompanyRepairServ;
	bool m_isCompanyFuel;
	static constexpr float m_percentageOfOrder = 0.9f;
	static constexpr float m_percentageOfInsured = 0.25f;
	static constexpr float m_percentageOfRepairServ = 0.1f;
	static constexpr float m_percentageOfFuel = 0.05f;
public:
	DriverIndependent(bool isCompanyInsured = false, bool isCompanyRepairServ = false, bool isCompanyFuel = false, const Driver& driver = Driver("undefined", 0, Car("undefined", "undefined", 0)))
		: m_isCompanyInsured{ isCompanyInsured }, m_isCompanyRepairServ{ isCompanyRepairServ }, m_isCompanyFuel{ isCompanyFuel }, m_driver{ driver }
	{
	}
	Driver& getDriver();
	void setSalary(float);
	float getSalary();
	bool isInsured();
	bool isRepairServ();
	bool isFuel();
	static float getPercentageOfOrder();
	static float getPercentageOfInsured();
	static float getPercentageOfRepairServ();
	static float getPercentageOfFuel();
	~DriverIndependent() {}
	friend std::istream& operator>> (std::istream& in, DriverIndependent&);
};

std::ostream& operator<< (std::ostream&, DriverIndependent&);
float operator+(float money, DriverIndependent& driver);
float operator+(DriverIndependent& driver, float money);
float operator+=(float money, DriverIndependent& driver);
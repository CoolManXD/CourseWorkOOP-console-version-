#include "driverIndependent.h"
#include "car.h"
#include <iostream>

Driver& DriverIndependent::getDriver()
{
	return m_driver;
}

void DriverIndependent::setSalary(float salary)
{
	m_salary = salary;
}

float DriverIndependent::getSalary()
{
	return m_salary;
}

bool DriverIndependent::isInsured()
{
	return m_isCompanyInsured;
}
bool DriverIndependent::isRepairServ()
{
	return m_isCompanyRepairServ;
}
bool DriverIndependent::isFuel()
{
	return m_isCompanyFuel;
}


float DriverIndependent::getPercentageOfOrder()
{
	return m_percentageOfOrder;
}

float DriverIndependent::getPercentageOfInsured()
{
	return m_percentageOfInsured;
}

float DriverIndependent::getPercentageOfRepairServ()
{
	return m_percentageOfRepairServ;
}

float DriverIndependent::getPercentageOfFuel()
{
	return m_percentageOfFuel;
}

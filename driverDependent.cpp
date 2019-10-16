#include "driverDependent.h"
#include "car.h"
#include <iostream>

Driver& DriverDependent::getDriver()
{
	return m_driver;
}

void DriverDependent::setSalary(float salary)
{
	m_salary = salary;
}

float DriverDependent::getSalary()
{
	return m_salary;
}

float DriverDependent::getPercentageOfOrder()
{
	return m_percentageOfOrder;
}
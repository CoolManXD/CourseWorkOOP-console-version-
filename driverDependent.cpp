#include "driverDependent.h"
#include "car.h"
#include <iostream>

//-------------------������� �������-------------------- 
void DriverDependent::setSalary(float salary)
{
	m_salary = salary;
}

float DriverDependent::getSalary()
{
	return m_salary;
}

//-------------------������� ����������� �����-------------------- 
float DriverDependent::getPercentageOfOrder()
{
	return m_percentageOfOrder;
}

//-------------------���������� ����������-------------------- 
std::ostream& operator<< (std::ostream& out, DriverDependent& driver)
{
	out << "Name: " << driver.getName() << "\nYear experience: " << driver.getYearExp() << "\n" << driver.getCar();
	out << "Salary: " << driver.getSalary() << "\n";
	return out;
}

std::istream& operator>> (std::istream& in, DriverDependent& driver)
{
	in >> dynamic_cast<Driver&>(driver);
	std::cout << "Salary: ";
	in >> driver.m_salary;
	return in;
}

float operator+(float money, DriverDependent& driver)
{
	return money + driver.getSalary();
}

float operator+(DriverDependent& driver, float money)
{
	return money + driver.getSalary();
}

float operator+=(float money, DriverDependent& driver)
{
	return money + driver.getSalary();
}

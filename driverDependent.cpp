#include "driverDependent.h"
#include "car.h"
#include <iostream>

//-------------------Функции доступа-------------------- 
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

//-------------------Геттеры статический полей-------------------- 
float DriverDependent::getPercentageOfOrder()
{
	return m_percentageOfOrder;
}

//-------------------Перегрузка операторов-------------------- 
std::ostream& operator<< (std::ostream& out, DriverDependent& driver)
{
	out << driver.getDriver();
	out << "Salary: " << driver.getSalary() << "\n";
	return out;
}

std::istream& operator>> (std::istream& in, DriverDependent& driver)
{
	in >> driver.getDriver();
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

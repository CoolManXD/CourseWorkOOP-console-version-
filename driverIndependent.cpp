#include "driverIndependent.h"
#include "car.h"
#include <iostream>

//-------------------������� �������-------------------- 
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

//-------------------������� ����������� �����-------------------- 
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

//-------------------���������� ����������-------------------- 

std::ostream& operator<< (std::ostream& out, DriverIndependent& driver)
{
	out << driver.getDriver();
	out << "Salary: " << driver.getSalary() << "\n";
	if (driver.isInsured()) out << "Use company insurance: +\n";
	else out << "Use company insurance: -\n";
	if (driver.isRepairServ()) out << "Use company repair service: +\n";
	else out << "Use company repair service: -\n";
	if (driver.isFuel()) out << "Use company fuel: +\n";
	else out << "Use company fuel: -\n";
	return out;
}

std::istream& operator>> (std::istream& in, DriverIndependent& driver)
{
	in >> driver.getDriver();
	std::cout << "Salary: ";
	in >> driver.m_salary;
	std::cout << "Use company insurance(+/-): ";
	char choosen;
	std::cin >> choosen;
	if (choosen == '+') driver.m_isCompanyInsured = true;
	else driver.m_isCompanyInsured = false;
	std::cout << "Use company repair service(+/-): ";

	std::cin >> choosen;
	if (choosen == '+') driver.m_isCompanyRepairServ = true;
	else driver.m_isCompanyRepairServ = false;
	std::cout << "Use company fuel(+/-): ";

	std::cin >> choosen;
	if (choosen == '+') driver.m_isCompanyFuel = true;
	else driver.m_isCompanyFuel = false;
	return in;
}

float operator+(float money, DriverIndependent& driver)
{
	return money + driver.getSalary();
}

float operator+(DriverIndependent& driver, float money)
{
	return money + driver.getSalary();
}

float operator+=(float money, DriverIndependent& driver)
{
	return money + driver.getSalary();
}
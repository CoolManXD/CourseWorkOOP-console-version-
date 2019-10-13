#include "driverDependent.h"
#include <iostream>

void DriverDependent::getInfoDriver()
{
	std::cout << "Name: " << m_name << "\nYear experience: " << m_yearExp << "\n";
	m_car.getAttributesCar();
}
std::string DriverDependent::getName()
{
	return m_name;
}
int DriverDependent::getYearExp()
{
	return m_yearExp;

}
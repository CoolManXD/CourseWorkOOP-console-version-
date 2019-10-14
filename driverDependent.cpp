#include "driverDependent.h"
#include "car.h"
#include <iostream>

void DriverDependent::getInfoDriver()
{
	std::cout << "Name: " << m_name << "\nYear experience: " << m_yearExp << "\n";
	m_car.getAttributesCar();
}
const std::string& DriverDependent::getName()
{
	return m_name;
}
int DriverDependent::getYearExp()
{
	return m_yearExp;

}
Car& DriverDependent::getCar()
{
	return m_car;
}
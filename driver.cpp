#include "driver.h"
#include "car.h"
#include <iostream>

void Driver::getInfoDriver()
{
	std::cout << "Name: " << m_name << "\nYear experience: " << m_yearExp << "\n";
	m_car.getAttributesCar();
}
const std::string& Driver::getName()
{
	return m_name;
}
int Driver::getYearExp()
{
	return m_yearExp;

}
Car& Driver::getCar()
{
	return m_car;
}

bool Driver::isBusy()
{
	return m_isBusy;
}
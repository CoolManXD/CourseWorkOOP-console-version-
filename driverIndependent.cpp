#include "driverIndependent.h"
#include <iostream>

void DriverIndependent::getInfoDriver()
{
	std::cout << "Name: " << m_name << "\nYear experience: " << m_yearExp << "\n";
	m_car.getAttributesCar();
} 
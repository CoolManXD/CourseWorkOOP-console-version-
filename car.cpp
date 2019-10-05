#include "car.h"
#include <iostream>

void Car::setAttributesCar(std::string model, std::string regPlate, int speed)
{
	m_model = model;
	m_regPlate = regPlate;
	m_speed = speed;
}
void Car::getAttributesCar()
{
	std::cout << "Model: " << m_model << "\nRegistation plate: " << m_regPlate << "\nSpeed: " << m_speed << "km/h\n\n";
}

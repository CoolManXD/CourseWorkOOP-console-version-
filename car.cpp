#include "car.h"
#include <iostream>

void Car::setAttributesCar(std::string model, std::string regPlate, bool isInsured)
{
	m_model = model;
	m_regPlate = regPlate;
	m_isInsured = isInsured;
}
void Car::getAttributesCar()
{
	std::cout << "Model: " << m_model << "\nRegistation plate: " << m_regPlate << "\nInsured: " << (m_isInsured == true ? "true" : "false") << "\n\n";
}

std::string Car::getModel()
{
	return m_model;
}
std::string Car::getRegPlate()
{
	return m_regPlate;
}
bool Car::isInsured()
{
	return m_isInsured;

}
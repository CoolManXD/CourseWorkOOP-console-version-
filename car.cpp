#include "car.h"
#include <iostream>

void Car::setAttributesCar(std::string model, std::string regPlate, bool isVip)
{
	m_model = model;
	m_regPlate = regPlate;
	m_isVip = isVip;
}
void Car::getAttributesCar()
{
	std::cout << "Model: " << m_model << "\nRegistation plate: " << m_regPlate << "\nVip: " << (m_isVip == true ? "true" : "false") << "\n\n";
}

const std::string& Car::getModel()
{
	return m_model;
}
const std::string& Car::getRegPlate()
{
	return m_regPlate;
}
bool Car::isVip()
{
	return m_isVip;
}
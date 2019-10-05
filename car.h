#pragma once
#include <string>

class Car {
private:
	std::string m_model;
	std::string m_regPlate;
	int m_speed;
public:
	Car(std::string model = "undefined", std::string regPlate = "undefined", int speed = 0)
		: m_model{ model }, m_regPlate{ regPlate }, m_speed{ speed }
	{
	}
	Car(const Car &cpyCar)
		: m_model{ cpyCar.m_model }, m_regPlate{ cpyCar.m_regPlate }, m_speed{ cpyCar.m_speed }
	{
	}
	void setAttributesCar(std::string model, std::string regPlate, int speed);
	void getAttributesCar();

	~Car() {}
};
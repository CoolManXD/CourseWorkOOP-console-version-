#pragma once
#include <string>

class Car {
private:
	std::string m_model;
	std::string m_regPlate;
	bool m_isInsured;
public:
	Car(std::string model = "undefined", std::string regPlate = "undefined", bool isInsured = 0)
		: m_model{ model }, m_regPlate{ regPlate }, m_isInsured{ isInsured }
	{
	}
	Car(const Car &cpyCar)
		: m_model{ cpyCar.m_model }, m_regPlate{ cpyCar.m_regPlate }, m_isInsured{ cpyCar.m_isInsured }
	{
	}
	
	void setAttributesCar(std::string model, std::string regPlate, bool isInsured);
	void getAttributesCar();
	std::string getModel();
	std::string getRegPlate();
	bool isInsured();

	~Car() {}
};
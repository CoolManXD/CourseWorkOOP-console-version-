#pragma once
#include <string>

class DriverDependent;
class DriverIndependent;

class Car {
private:
	std::string m_model;
	std::string m_regPlate;
	bool m_isVip;
public:
	Car(std::string model = "undefined", std::string regPlate = "undefined", bool isVip = 0)
		: m_model{ model }, m_regPlate{ regPlate }, m_isVip{ isVip }
	{
	}
	Car(const Car &cpyCar)
		: m_model{ cpyCar.m_model }, m_regPlate{ cpyCar.m_regPlate }, m_isVip{ cpyCar.m_isVip }
	{
	}
	
	void setAttributesCar(std::string model, std::string regPlate, bool isInsured);
	void getAttributesCar();
	const std::string& getModel();
	const std::string& getRegPlate();
	bool isVip();
	~Car() {}
};
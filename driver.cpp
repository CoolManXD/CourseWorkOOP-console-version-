#include "driver.h"
#include "car.h"
#include <iostream>

//-------------------Функции доступа-------------------- 
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

//-------------------Перегрузка операторов-------------------- 
std::ostream& operator<< (std::ostream& out, Driver& driver)
{
	out << "Name: " << driver.getName() << "\nYear experience: " << driver.getYearExp() << "\n" << driver.getCar();
	return out;
}

std::istream& operator>> (std::istream& in, Driver& driver)
{
	std::cout << "Name: ";
	in >> driver.m_name;
	std::cout << "Year experience: ";
	in >> driver.m_yearExp;
	in >> driver.getCar();
	return in;
}
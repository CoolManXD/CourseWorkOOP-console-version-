#include "taxiPark.h"
#include <fstream>
#include <iostream>

void TaxiPark::loadData() {
	std::ifstream fsCar("dataBase\\carsDependent.txt");
	std::ifstream fsDriver("dataBase\\driversDependent.txt");
	std::string name;
	int yearExp;
	std::string model;
	std::string regPlate;
	char symbol;
	bool isVip;
	while (!fsCar.eof())
	{
		fsDriver >> name;
		fsDriver >> yearExp;
		fsCar >> model;
		fsCar >> regPlate;
		fsCar >> symbol;
		isVip = (symbol == '+') ? true : false;
		driversDependent.push_back(DriverDependent(Driver(name, yearExp, Car(model, regPlate, isVip))));
	}
	fsCar.close();
	fsDriver.close();
	fsCar.open("dataBase\\carsIndependent.txt");
	fsDriver.open("dataBase\\driversIndependent.txt");
	bool isInsured;
	bool isRepairServ;
	bool isFuel;
	char symbol1;
	char symbol2;
	char symbol3;
	while (!fsCar.eof())
	{
		fsDriver >> name;
		fsDriver >> yearExp;
		fsDriver >> symbol1;
		fsDriver >> symbol2;
		fsDriver >> symbol3;
		fsCar >> model;
		fsCar >> regPlate;
		fsCar >> symbol;
		isVip = (symbol == '+') ? true : false;
		isInsured = (symbol1 == '+') ? true : false;
		isRepairServ = (symbol2 == '+') ? true : false;
		isFuel = (symbol3 == '+') ? true : false;
		driversIndependent.push_back(DriverIndependent(isInsured, isRepairServ, isFuel, Driver(name, yearExp, Car(model, regPlate, isVip))));
	}
}

bool TaxiPark::checkLoadData()
{
	bool OK{ true };
	for (auto it = driversDependent.begin(); it != driversDependent.end(); ++it)
	{
		if (it->getDriver().getName() == "")
		{
			std::cout << "Mistake in name\n";
			OK = false;
		}
		if (it->getDriver().getYearExp() < 0 || it->getDriver().getYearExp() > 200)
		{
			std::cout << "Mistake in year of experience\n";
			OK = false;
		}
		if (it->getDriver().getCar().getModel() == "")
		{
			std::cout << "mistake in name of model\n";
			OK = false;
		}
		if (it->getDriver().getCar().getRegPlate() == "")
		{
			std::cout << "mistake in registation plate\n";
			OK = false;
		}
	}
	for (auto it = driversIndependent.begin(); it != driversIndependent.end(); ++it)
	{
		if (it->getDriver().getName() == "")
		{
			std::cout << "Mistake in name\n";
			OK = false;
		}
		if (it->getDriver().getYearExp() < 0 || it->getDriver().getYearExp() > 200)
		{
			std::cout << "Mistake in year of experience\n";
			OK = false;
		}
		if (it->getDriver().getCar().getModel() == "")
		{
			std::cout << "mistake in name of model\n";
			OK = false;
		}
		if (it->getDriver().getCar().getRegPlate() == "")
		{
			std::cout << "mistake in registation plate\n";
			OK = false;
		}
	}
	return OK;
}

void TaxiPark::receiveOrder(Client* client)
{
	m_client = client;
}

void TaxiPark::completeOrder()
{
	delete m_client;
}

// DriverDependent TaxiPark::getDependent(int index)
//{
//	return driversDependent[index];
//}
// DriverIndependent TaxiPark::getIndependent(int index)
//{
//	return driversIndependent[index];
//}

//Driver* TaxiPark::operator[] (const int index)
//{
//	return drivers[index];
//}
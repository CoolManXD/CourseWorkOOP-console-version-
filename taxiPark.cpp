#include "taxiPark.h"
#include <fstream>

void TaxiPark::loadData() {
	std::ifstream fsCar("dataBase\\carsDependent.txt");
	std::ifstream fsDriver("dataBase\\driversDependent.txt");
	while (!fsCar.eof())
	{
		std::string name;
		int yearExp;
		std::string model;
		std::string regPlate;
		int speed;
		fsDriver >> name;
		fsDriver >> yearExp;
		fsCar >> model;
		fsCar >> regPlate;
		fsCar >> speed;
		driversDependent.push_back(DriverDependent(name, yearExp, Car(model, regPlate, speed)));
	}
	fsCar.close();
	fsDriver.close();
	fsCar.open("dataBase\\carsIndependent.txt");
	fsDriver.open("dataBase\\driversIndependent.txt");
	while (!fsCar.eof())
	{
		std::string name;
		int yearExp;
		std::string model;
		std::string regPlate;
		int speed;
		fsDriver >> name;
		fsDriver >> yearExp;
		fsCar >> model;
		fsCar >> regPlate;
		fsCar >> speed;
		driversIndependent.push_back(DriverIndependent(name, yearExp, Car(model, regPlate, speed)));
	}
}

DriverDependent TaxiPark::getDependent(int index)
{ 
	return driversDependent[index];
}
DriverIndependent TaxiPark::getIndependent(int index)
{
	return driversIndependent[index];
}

//Driver* TaxiPark::operator[] (const int index)
//{
//	return drivers[index];
//}
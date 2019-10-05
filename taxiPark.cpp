#include "taxiPark.h"
#include <fstream>

void TaxiPark::loadData() {
	std::ifstream fsCar("dataBase\\cars.txt");
	std::ifstream fsDriver("dataBase\\drivers.txt");
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
		drivers.push_back(Driver(name, yearExp, Car(model, regPlate, speed)));
	}
	fsCar.close();
	fsDriver.close();
}

Driver TaxiPark::getItem(int index) 
{ 
	return drivers[index]; 
}

//Driver* TaxiPark::operator[] (const int index)
//{
//	return drivers[index];
//}
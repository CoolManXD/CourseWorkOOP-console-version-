#include <iostream>
#include "map.h"
#include "taxiPark.h"

int main()
{
	Map map;
	TaxiPark park;
	park.getItem(0).getInfoDriver();
	

	Driver driver1("Serhii", 5, Car("Bentley", "YY999YY", 150));
	driver1.getInfoDriver();

	Car car1;
	Car car2("BMW", "AA000AA", 100);
	Car car3{ car2 };
	std::cout << "Car1 (default constructor)" << std::endl;
	car1.getAttributesCar();
	std::cout << "Car2 (initialization constructor)" << std::endl;
	car2.getAttributesCar();
	std::cout << "Car3 == Car2 (copy constructor)" << std::endl;
	car3.getAttributesCar();
	std::cout << "Car3 (changed)" << std::endl;
	car3.setAttributesCar("Audi", "BB111BB", 120);
	car3.getAttributesCar();

	system("pause");
	return 0;
}
#include <iostream>
#include "map.h"
#include "driverMap.h"
#include "taxiPark.h"
#include "client.h"
int main()
{
	
	Map map;
	DriverMap driverMap{ map };
	TaxiPark park;
	park.checkLoadData();
	Client *client = new Client{ map };
	std::cout << client->getDesination();
	park.receiveOrder(client);
	park.completeOrder();

	/*park.getDependent(0).getInfoDriver();
	park.getIndependent(0).getInfoDriver();
	park.getDependent(2).getInfoDriver();

	
	DriverDependent driver1("Serhii", 5, Car("Bentley", "YY999YY", true));
	driver1.getInfoDriver();

	Car car1;
	Car car2("BMW", "AA000AA", true);
	Car car3{ car2 };
	std::cout << "Car1 (default constructor)" << std::endl;
	car1.getAttributesCar();
	std::cout << "Car2 (initialization constructor)" << std::endl;
	car2.getAttributesCar();
	std::cout << "Car3 == Car2 (copy constructor)" << std::endl;
	car3.getAttributesCar();
	std::cout << "Car3 (changed)" << std::endl;
	car3.setAttributesCar("Audi", "BB111BB", false);
	car3.getAttributesCar();*/

	system("pause");
	return 0;
}






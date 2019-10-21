#include <iostream>
#include "map.h"
#include "driverMap.h"
#include "taxiPark.h"
#include "client.h"
#include <conio.h>

int main()
{

	Map map;
	/*DriverMap driverMap{ map };*/
	TaxiPark park;
	park.setDriverMap(new DriverMap{ map });
	
	int chosen; 
	bool BOOL = true; 
	while (BOOL)
	{
		system("cls");
		std::cout << "made by Yanchuk Serhii, IS-82, TaxiPark" << std::endl << std::endl;
		std::cout << "-----------MENU----------" << std::endl;
		std::cout << "1 - Make order" << std::endl;
		std::cout << "2 - Apply for a job" << std::endl;
		std::cout << "3 - Show drivers' profiles" << std::endl;
		std::cout << "0 - exit" << std::endl;
		std::cout << "Chosen: ";
		std::cin >> chosen;
		std::cin.ignore();
		switch (chosen)
		{
		case 1:
		{
			park.receiveOrder(new Client{ map });
			park.completeOrder();
			std::cout << "Press any key\n";
			_getch();
			break;
		}
		case 2:
		{
			std::cout << "Will you use your car? (+/-)" << std::endl;
			char what;
			std::cin >> what;
			std::cin.ignore();
			if (what == '+') park.addIndependentDriver();
			else park.addDependentDriver();
			std::cout << "Press any key\n";
			_getch();
			break;
		}
		case 3:
		{
			std::cout << park;
			std::cout << "Press any key\n";
			_getch();
			break;
		}
		case 0:
		{
			BOOL = false;
			std::cout << "Bye bye" << std::endl;
			std::cout << "Press any key\n";
			_getch();
			break;
		}
		default:
		{
			std::cout << "Ops! Try again!" << std::endl;
			std::cout << "Press any key" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		}
	}


	/*std::cout << park.getDependent(0).getDriverMap()->m_trafficJams[0][0].first;
	park.addDependentDriver();
	std::cout << std::endl;
	park.addIndependentDriver();
	std::cout << std::endl;
	std::cout << park;
	std::cout << std::endl;
	park.paySalaries();
	std::cout << park.getIndependent(0).getName() << std::endl;
	park.checkLoadData();
	std::cout << std::endl;*/
	


	system("pause");
	return 0;
}






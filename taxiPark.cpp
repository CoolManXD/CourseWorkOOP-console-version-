#include "taxiPark.h"
#include "client.h"
#include <fstream>
#include <iostream>

//-------------------Загрузка данных с файла и проверка-------------------- 

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
		fsCar >> model;
		if (fsCar.eof()) break;
		fsCar >> regPlate;
		fsCar >> symbol;
		fsDriver >> name;
		fsDriver >> yearExp;
		isVip = (symbol == '+') ? true : false;
		driversDependent.push_back(DriverDependent(name, yearExp, Car(model, regPlate, isVip)));
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
		fsCar >> model;
		if (fsCar.eof()) break;
		fsCar >> regPlate;
		fsCar >> symbol;
		fsDriver >> name;
		fsDriver >> yearExp;
		fsDriver >> symbol1;
		fsDriver >> symbol2;
		fsDriver >> symbol3;
		isVip = (symbol == '+') ? true : false;
		isInsured = (symbol1 == '+') ? true : false;
		isRepairServ = (symbol2 == '+') ? true : false;
		isFuel = (symbol3 == '+') ? true : false;
		driversIndependent.push_back(DriverIndependent(isInsured, isRepairServ, isFuel, name, yearExp, Car(model, regPlate, isVip)));
	}
}

bool TaxiPark::checkLoadData()
{
	bool OK{ true };
	for (auto it = driversDependent.begin(); it != driversDependent.end(); ++it)
	{
		if (it->getName() == "")
		{
			std::cout << "Mistake in name\n";
			OK = false;
		}
		if (it->getYearExp() < 0 || it->getYearExp() > 200)
		{
			std::cout << "Mistake in year of experience\n";
			OK = false;
		}
		if (it->getCar().getModel() == "")
		{
			std::cout << "mistake in name of model\n";
			OK = false;
		}
		if (it->getCar().getRegPlate() == "")
		{
			std::cout << "mistake in registation plate\n";
			OK = false;
		}
	}
	for (auto it = driversIndependent.begin(); it != driversIndependent.end(); ++it)
	{
		if (it->getName() == "")
		{
			std::cout << "Mistake in name\n";
			OK = false;
		}
		if (it->getYearExp() < 0 || it->getYearExp() > 200)
		{
			std::cout << "Mistake in year of experience\n";
			OK = false;
		}
		if (it->getCar().getModel() == "")
		{
			std::cout << "mistake in name of model\n";
			OK = false;
		}
		if (it->getCar().getRegPlate() == "")
		{
			std::cout << "mistake in registation plate\n";
			OK = false;
		}
	}
	return OK;
}

void TaxiPark::setDriverMap(DriverMap* map)
{
	driversDependent[0].setDriverMap(map);
}

//----------------Получение и выполнение заказа------------------
void TaxiPark::receiveOrder(Client* client)
{
	m_client = client;
}

void TaxiPark::completeOrder()
{
	Driver* driver = NULL;
	for (auto it = driversDependent.begin(); it != driversDependent.end(); ++it)
	{
		if (!(it->isBusy()))
		{
			driver = &(*it);
			it->changeIsBusy();
			break;
		}
	}
	if (driver == NULL)
	{
		for (auto it = driversIndependent.begin(); it != driversIndependent.end(); ++it)
		{
			if (!(it->isBusy()))
			{
				driver = &(*it);
				it->changeIsBusy();
				break;
			}
		}
	}
	if (driver == NULL)
	{
		std::cout << "Sorry. No free cars :(\n";
		delete m_client;
		m_client = NULL;
		return;
	}
	/*DriverDependent* driver2 = dynamic_cast<DriverDependent*>(driver);*/
	float way = driver->findWay(driver->getLocation(), m_client->getLocation());
	way += driver->findWay(m_client->getLocation(), m_client->getDestination());
	std::cout << "All trip will take " << way << " minutes\n";
	driver->setLocation(m_client->getDestination());
	delete m_client;
	m_client = NULL;
}

//----------------Получение конкретного водителя------------------
DriverDependent& TaxiPark::getDependent(const int index)
{
	return driversDependent[index];
}
DriverIndependent& TaxiPark::getIndependent(const int index)
{
	return driversIndependent[index];
}

//----------------Выплата зарплаты------------------
void TaxiPark::paySalaries()
{
	float totalSalary{ 0 };
	for (auto it = driversDependent.begin(); it != driversDependent.end(); ++it)
	{
		totalSalary = totalSalary + (*it);
		it->setSalary(0);
	}
	for (auto it = driversIndependent.begin(); it != driversIndependent.end(); ++it)
	{
		totalSalary = totalSalary + (*it);
		it->setSalary(0);
	}
	m_earnMoney -= totalSalary;
}

//-------------------Добавление в базу новых водителей-------------------- 
void TaxiPark::addDependentDriver()
{
	std::cout << "\nFill profile (dependent driver) \n\n";
	DriverDependent driver;
	std::cin >> driver;
	driversDependent.push_back(driver);
}

void TaxiPark::addIndependentDriver()
{
	std::cout << "Fill profile (independent driver) \n\n";
	DriverIndependent driver;
	std::cin >> driver;
	driversIndependent.push_back(driver);
}

//-------------------Перегрузки операторов-------------------- 
std::ostream& operator<< (std::ostream& out, TaxiPark& park)
{
	int i = 1;
	out << "Dependent drivers\n";
	for (auto it = park.driversDependent.begin(); it != park.driversDependent.end(); ++it)
	{
		out << "\n" << i++ << ")\n" << *it;
	}
	i = 1;
	out << "\nIndependent drivers\n";
	for (auto it = park.driversIndependent.begin(); it != park.driversIndependent.end(); ++it)
	{
		out << "\n" << i++ << ")\n" << *it;
	}
	return out;
}
#include "map.h"
#include <fstream>
#include <iostream>

//-------------------Загрузка карты(графа) с файла-------------------- 
void Map::loadMap()
{
	std::ifstream fs("dataBase\\listOfStreets.txt");
	std::string street;
	int index;
	while (!fs.eof())
	{
		fs >> street;
		fs >> index;
		listOfStreets.insert(std::make_pair(street, index));
	}
	fs.close();
	fs.open("dataBase\\map.txt");
	std::string from, to;
	float duration;
	fs >> quantityStreet;
	mapOfTown.resize(quantityStreet);
	while (!fs.eof())
	{
		fs >> from;
		fs >> to;
		fs >> duration;
		/*map[from[0] - 49].push_back(std::pair<std::string, int>(to, duration)); // код Аски '0' = 48
		map[to[0] - 49].push_back(std::pair<std::string, int>(from, duration));*/
		mapOfTown[listOfStreets[from]].push_back(std::make_pair(listOfStreets[to], duration)); 
		mapOfTown[listOfStreets[to]].push_back(std::make_pair(listOfStreets[from], duration));
	}
	fs.close();
}

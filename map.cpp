#include "map.h"
#include <fstream>
#include <iostream>

void Map::loadMap()
{
	std::ifstream fs("dataBase\\map.txt");
	std::string from, to;
	int duration;
	fs >> quantityStreet;
	map.resize(quantityStreet);
	while (!fs.eof())
	{
		fs >> from;
		fs >> to;
		fs >> duration;
		map[from[0] - 49].push_back(std::pair<std::string, int>(to, duration)); // код јски '0' = 48
		map[to[0] - 49].push_back(std::pair<std::string, int>(from, duration));
		/*map[from[0]].push_back(std::make_pair(to, duration));
		map[to[0]].push_back(std::make_pair(from, duration));*/
	}
	fs.close();
}

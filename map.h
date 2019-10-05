#pragma once
#include <vector>
#include <string>

class DriverMap;

class Map {
private:
	int quantityStreet;
	std::vector<std::vector<std::pair<std::string, int>>> map;
	const int INF{ 1000000000 };
	void loadMap();
public:
	Map() 
	{
		loadMap();
	}
	friend class DriverMap;
};
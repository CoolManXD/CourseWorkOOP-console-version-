#pragma once
#include <string>

class Map;

class Client
{
private:
	const Map& m_map;
	std::string m_name;
	std::string m_location;
	std::string m_destination;
public:
	Client(const Map& map);
	Client(const Map& map, std::string name, std::string location, std::string destination);
	std::string getLocation();
	std::string getDesination();
};
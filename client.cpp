#include "client.h"
#include "map.h"
#include <iostream>

Client::Client(const Map& map)
{
	std::cout << "Fill profile\n";
	std::cout << "Name: ";
	std::getline(std::cin, m_name);
	for (int i=0; i<map.)
	std::cout << "Location: ";
	std::getline(std::cin, m_location);
	std::cout << "Destination: ";
	std::getline(std::cin, m_destination);
}
Client::Client(std::string name, std::string location, std::string destination)
	: m_name{ name }, m_location{ location }, m_destination{ destination }
{

}
std::string Client::getLocation()
{
	return m_location;
}
std::string Client::getDesination()
{
	return m_destination;
}
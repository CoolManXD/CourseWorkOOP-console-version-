#pragma once
#include <string>

class TaxiService
{
public:
	TaxiService() {};
	virtual const std::string& getLocation() = 0;
	virtual void setLocation(const std::string&) = 0;
	virtual void changeIsBusy() = 0;
	virtual void setTimeAttributes(double) = 0;
	virtual float findWay(const std::string&, const std::string&) = 0;
	virtual void calculatePrice(double) = 0;
	virtual ~TaxiService() {}
};


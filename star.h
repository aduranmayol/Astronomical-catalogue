#ifndef STAR_H
#define STAR_H
#include <string> 
#include "baseclass.h"
class Star : public AstronomicalObject {
private:
	std::string name;
	std::string type;
	double mass; // in solar masses
	double radius; // in solar radius
	double distance; // in parsecs
	double temperature; // in Kelvin
	double apparentmagnitude;
public:
	Star(std::string n, std::string t, double m, double r, double d, double temp, double a); // constructor
	std::string getType() const override;
	std::string getName() const override;
	double getMass() const override;
	double getRadius() const override;
    double getDistance() const override;
    double getTemperature() const override;
    double getApparentMagnitude() const override;
    double getLuminosity();
	std::string spectraltype();
};
#endif
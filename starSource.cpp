#include "star.h"
#include <cmath>
#include <vector>
#include <string>
Star::Star(std::string n, std::string t, double m, double r, double d, double temp, double a)
	: name(n), type(t), mass(m), radius(r), distance(d), temperature(temp), apparentmagnitude(a)
{} // constructor implementation
std::string Star::getType() const
{
	return "Star";
}
std::string Star::getName() const
{
	return name;
}
double Star::getMass() const
{
	return mass;
}
double Star::getRadius() const
{
	return radius;
}
double Star::getDistance() const
{
	return distance;
}
double Star::getTemperature() const
{
	return temperature;
}
double Star::getApparentMagnitude() const
{
	return apparentmagnitude;
}
double Star::getLuminosity()
{
	double distance_pc = distance / 3.261563;
	double absolutemagnitude = apparentmagnitude - 5 * log10(distance_pc / 10);
	return pow(10, -(absolutemagnitude / 2.512)); //in solar luminosities
}
std::string Star::spectraltype()
{
	if (temperature <= 3500) {
		return "M";
	}
	if (3500 < temperature && temperature <= 5000) {
		return "K";
	}
	if (5000 < temperature && temperature <= 6000) {
		return "G";
	}
	if (6000 < temperature && temperature <= 7500) {
		return "F";
	}
	if (7500 < temperature && temperature <= 10000) {
		return "A";
	}
	if (10000 < temperature && temperature <= 30000) {
		return "B";
	}
	if (30000 < temperature) {
		return "O";
	}
}
#include "galaxy.h"
#include <cmath>
#include <vector>
#include <string>
Galaxy::Galaxy(std::string n, std::string t, double m, double r, double d, double temp, double a)
    : name(n), type(t), mass(m), radius(r), distance(d), temperature(temp), apparentmagnitude(a)
{} // constructor implementation
std::string Galaxy::getType() const // implementation of all member functions
{
    return "Galaxy";
}
std::string Galaxy::getName() const
{
    return name;
}
double Galaxy::getMass() const
{
    return mass;
}
double Galaxy::getRadius() const
{
    return radius;
}
double Galaxy::getDistance() const
{
    return distance;
}
double Galaxy::getTemperature() const
{
    return temperature;
}
double Galaxy::getApparentMagnitude() const
{
    return apparentmagnitude;
}
double Galaxy::getLuminosity()
{
    double distance_pc = distance / 3.261563;
    double absolutemagnitude = apparentmagnitude - 5 * log10(distance_pc / 10);
    return pow(10, -(absolutemagnitude / 2.512)); //in solar luminosities
}
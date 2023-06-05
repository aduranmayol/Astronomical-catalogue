#include <cmath>
#include <vector>
#include <string>
#include "other.h"
Other::Other(std::string n, std::string t, double m, double r, double d, double temp, double a)
    : name(n), type(t), mass(m), radius(r), distance(d), temperature(temp), apparentmagnitude(a)
{} // constructor implementation
std::string Other::getType() const
{
    return "Other";
}
std::string Other::getName() const
{
    return name;
}
double Other::getMass() const
{
    return mass;
}
double Other::getRadius() const
{
    return radius;
}
double Other::getDistance() const
{
    return distance;
}
double Other::getTemperature() const
{
    return temperature;
}
double Other::getApparentMagnitude() const
{
    return apparentmagnitude;
}
double Other::getLuminosity()
{
    double distance_pc = distance / 3.261563;
    double absolutemagnitude = apparentmagnitude - 5 * log10(distance_pc / 10);
    return pow(10, -(absolutemagnitude / 2.512)); //in solar luminosities
}

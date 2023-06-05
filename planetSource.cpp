#include "planet.h"
#include <cmath>
#include <vector>
#include <string>
Planet::Planet(std::string n, std::string t, double m, double r, double d, double temp, double a)
    : name(n), type(t), mass(m), radius(r), distance(d), temperature(temp), apparentmagnitude(a)
{} // constructor implementation
std::string Planet::getType() const
{
    return "Planet";
}
std::string Planet::getName() const
{
    return name;
}
double Planet::getMass() const
{
    return mass;
}
double Planet::getRadius() const
{
    return radius;
}
double Planet::getDistance() const
{
    return distance;
}
double Planet::getTemperature() const
{
    return temperature;
}
double Planet::getApparentMagnitude() const
{
    return apparentmagnitude;
}
double Planet::getLuminosity()
{
    double distance_pc = distance / 3.261563;
    double absolutemagnitude = apparentmagnitude - 5 * log10(distance_pc / 10);
    return pow(10, -(absolutemagnitude / 2.512)); //in solar luminosities
}
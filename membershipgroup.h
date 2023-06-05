#ifndef MEMBERSHIPGROUP_H
#define MEMBERSHIPGROUP_H
#include "baseclass.h"
#include <string>
#include <vector>
class Group;  // forward declaration to fix circular dependency
class Membership {
public:
    Membership(AstronomicalObject* object, Group* group) : object_(object), group_(group) 
    {}
    AstronomicalObject* getObject() const 
    {
        return object_;
    }
    Group* getGroup() const 
    {
        return group_; 
    }

private:
    // Pointer to the astronomical object associated with this membership.
    AstronomicalObject* object_;
    // Pointer to the group associated with this membership.
    Group* group_;
};

class Group {
public:
    Group(const std::string& name) : name_(name) 
    {}
    std::string getName() const 
    { 
        return name_;
    }
    void addMember(AstronomicalObject* object) 
    {
        // Create a new membership with the object and this group.
        Membership membership(object, this);
        members_.push_back(membership);
    }
    // Accessor function to get a list of all members in this group.
    std::vector<Membership> getMembers() const 
    {
        return members_; 
    }
private:
    std::string name_;
    // The list of members in this group.
    std::vector<Membership> members_;
};

#endif
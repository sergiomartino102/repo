#include "Member.hpp"

Member::Member(std::string id, std::string name, std::string phone, std::string email, std::string profileURL)
{
    this->id = id;
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->profileURL = profileURL;
}

Member::Member()
{
}

std::string Member::getId() const
{
    return this->id;
}

bool operator==(const Member &a, const Member &b)
{
    return (a.getId() == b.getId());
}
#ifndef LINKEDINMANAGERIMPL_HPP
#define LINKEDINMANAGERIMPL_HPP

#include "service/LinkedinManager.hpp"

class LinkedinManagerImpl : public LinkedinManager
{
public:
    LinkedinManagerImpl();

    bool addMember(Member member);

    bool addConnection(std::string memberID1, std::string memberID2);

    int getConnectionDegree(std::string memberID1, std::string memberID2);

private:
};

#endif
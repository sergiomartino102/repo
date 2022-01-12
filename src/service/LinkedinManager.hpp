#ifndef __LINKEDIN_MANAGER__
#define __LINKEDIN_MANAGER__

#include <string>
#include "domain/Member.hpp"

class LinkedinManager
{
public:
  virtual bool addMember(Member member) = 0;

  virtual bool addConnection(std::string memberID1, std::string memberID2) = 0;

  virtual int getConnectionDegree(std::string memberID1, std::string memberID2) = 0;
};

#endif

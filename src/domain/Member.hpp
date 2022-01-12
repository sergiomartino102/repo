#ifndef __MEMBER__
#define __MEMBER__

#include <string>

class Member
{
private:
  std::string id;
  std::string name;
  std::string phone;
  std::string email;
  std::string profileURL;

public:
  Member(std::string id, std::string name, std::string phone, std::string email, std::string profileURL);
  Member();
  std::string getId() const;
  friend bool operator==(const Member &a, const Member &b);
};

#endif

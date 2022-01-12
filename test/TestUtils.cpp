#include "TestUtils.hpp"
#include <random>

std::string TestUtils::random_string(size_t length)
{
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::string str1 = "";
    for (int i = 0; i < length; i++)
    {
        str1 = str1 + str.at(rand() % 20);
    }
    return str1; // assumes 32 < number of characters in str
}

 Member  TestUtils::generateMember(const char name[]) {
     std::string nameWithDot = std::string(name);
      replace(nameWithDot, std::string(" "), std::string("."));
        return Member(TestUtils::random_string(10), name, "+91-1234512345",  nameWithDot+ "@gmail.com", nameWithDot + ".me");
    }

bool TestUtils::replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
#ifndef TESTUTILS_HPP
#define TESTUTILS_HPP

#include "domain/Member.hpp"

#include <map>

class TestUtils
{
public:
    static std::string random_string(size_t length);

    static Member generateMember(const char name[]);

    static bool replace(std::string &str, const std::string &from, const std::string &to);
};

#endif
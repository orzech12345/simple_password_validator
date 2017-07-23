#include "passwordSaftyChecker.hpp"
#include <list>
#include <algorithm>

namespace component  {
std::list<char> specialChar {
    '~',
    '!',
    '@',
    '#',
    '$',
    '%',
    '^',
    '&',
    '*',
    '(',
    ')',
    '_',
    '-',
    '+',
    '='
};
}

bool PasswordSaftyChecker::isPasswordStrong(std::string str) const
{
    int validator = 0;

    if (containAnyNumber(str))
        validator++;
    if (containAnySpecialChar(str))
       validator++;
    if (containAnyUpperChar(str))
       validator++;

    return validator >= 2;
}

bool PasswordSaftyChecker::isPasswordValid(std::string str) const
{  
    return !str.empty() &&
           !tooShortPassword(str) &&
           !tooLongPassword(str) &&
           isPasswordStrong(str);
}

bool PasswordSaftyChecker::containAnyNumber(std::string str) const
{
    auto findNumber = std::find_if(str.begin(), str.end(), [](const char c) {
        int ascii = static_cast<int>(c);
        return ascii <= 57 && ascii >= 48 ;
    });
    return findNumber != str.end();
}

bool PasswordSaftyChecker::containAnyUpperChar(std::string str) const
{
    auto findUpperChar = std::find_if(str.begin(), str.end(), [](const char c) {
        int ascii = static_cast<int>(c);
        return ascii <= 90 && ascii >= 65 ;
    });
    return findUpperChar != str.end();
}

bool PasswordSaftyChecker::containAnySpecialChar(std::string str) const
{
    for (const auto& singleChar : str) {
        auto findSpecialChar = std::find(component::specialChar.begin(),
                            component::specialChar.end(), singleChar);
        if (findSpecialChar != component::specialChar.end()) {
            return true;
        }
    }
    return false;
}

bool PasswordSaftyChecker::tooShortPassword(std::string str) const
{
    return str.size() < 8;
}

bool PasswordSaftyChecker::tooLongPassword(std::string str) const
{
    return str.size() > 20;
}

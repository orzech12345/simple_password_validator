#pragma once

#include "abstractValidator.hpp"

class PasswordSaftyChecker : public AbstractValidator
{
public:
    bool isPasswordValid(std::string str) const;
private:
    bool isPasswordStrong(std::string str) const;

    bool tooShortPassword(std::string str) const;
    bool tooLongPassword(std::string str) const;

    bool containAnyNumber(std::string str) const;
    bool containAnySpecialChar(std::string str) const;
    bool containAnyUpperChar(std::string str) const;
};

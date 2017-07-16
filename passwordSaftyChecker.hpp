#pragma once

#include "abstractValidator.hpp"

class PasswordSaftyChecker : public AbstractValidator
{
public:
    bool isPasswordValid(std::string str) const;
};

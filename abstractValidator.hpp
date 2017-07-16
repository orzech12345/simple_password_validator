#pragma once

#include <string>

class AbstractValidator
{
public:
    virtual bool isPasswordValid(std::string) const = 0;
    virtual ~AbstractValidator() = default;
};


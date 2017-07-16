#pragma once

#include <string>

class AbstractValidator
{
public:
    virtual bool isValid(std::string) const = 0;
    virtual ~AbstractValidator() = default;
};


#pragma once

#include <memory>

#include "passwordSaftyChecker.hpp"

class Password
{
public:
    Password(std::shared_ptr<AbstractValidator> v =
            std::shared_ptr<AbstractValidator>(new PasswordSaftyChecker()));

    bool isPasswordValid();
    bool operator != (const Password& pass) const;
    bool operator == (const Password& pass) const;

    void setValue(std::string value);

private:
    std::string value;
    std::shared_ptr<AbstractValidator> validator;

};


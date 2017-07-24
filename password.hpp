#pragma once

#include <memory>

#include <passwordSaftyChecker.hpp>

class Password
{
public:
    Password(std::shared_ptr<AbstractValidator> val =
            std::shared_ptr<AbstractValidator>(new PasswordSaftyChecker()));

    void setValue(std::string v);

    bool isPasswordValid();
    bool isPasswordStrong();

    bool operator!=(const Password& rval) const;
    bool operator==(const Password& rval) const;

private:
    std::string value;
    std::shared_ptr<AbstractValidator> validator;

};

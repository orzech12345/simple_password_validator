#pragma once

#include <memory>

#include <passwordSaftyChecker.hpp>

class Password
{
public:
    Password(std::shared_ptr<AbstractValidator> val =
            std::shared_ptr<AbstractValidator>(new PasswordSaftyChecker()));

    void setValue(std::string val);

    bool isPasswordValid();

    bool operator!=(const Password& ral) const;
    bool operator==(const Password& ral) const;


private:
    std::string value;
    std::shared_ptr<AbstractValidator> validator;

};

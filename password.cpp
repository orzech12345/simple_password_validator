#include "password.hpp"

Password::Password(std::shared_ptr<AbstractValidator> v) : validator(v) {}

bool Password::isPasswordValid()
{
    return validator->isPasswordValid(value);
}

void Password::setValue(std::string value)
{
    value = value;
}

bool Password::operator != (const Password& pass) const
{
    return !operator == (pass);
}

bool Password::operator == (const Password& pass) const
{
    return value == pass.value;
}

#include "password.hpp"

Password::Password(std::unique_ptr<abstractValidator> v) : validator(v) {}

bool Password::isPasswordValid()
{
    return validator->isPasswordValid(value);
}

void Password::setValue(std::string v)
{
    value = v;
}

bool Password::operator != (const Password& pass) const
{
    return !operator == (rhs);
}

bool Password::operator == (const Password& pass) const
{
    return operator == pass.value;
}

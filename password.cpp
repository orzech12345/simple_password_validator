#include "password.hpp"

Password::Password(std::shared_ptr<AbstractValidator> val) : validator(val) {}

bool Password::isPasswordValid()
{
    return validator->isPasswordValid(value);
}

void Password::setValue(std::string val)
{
    value = val;
}

bool Password::operator != (const Password& ral) const
{
    return !operator==(ral);
}

bool Password::operator==(const Password& ral) const
{
    return value == ral.value;
}

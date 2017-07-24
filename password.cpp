#include "password.hpp"

Password::Password(std::shared_ptr<AbstractValidator> val) : validator(val) {}

bool Password::isPasswordValid()
{
    return validator->isPasswordValid(value);
}

void Password::setValue(std::string v)
{
    value = v;
}

bool Password::operator != (const Password& rval) const
{
    return !operator==(rval);
}

bool Password::operator==(const Password& rval) const
{
    return value == rval.value;
}

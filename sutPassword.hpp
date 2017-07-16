#pragma once

#include "password.hpp"
#include <gtest/gtest.h>

class SutPassword : public ::testings::Test
{
public:
    SutPassword() : validator(new PasswordSaftyValidatorMock)
    {
        sut = Password(validator);
    }
private:
    std::shared_ptr<PasswordSaftyValidatorMock> validator;
    Password sut;
};

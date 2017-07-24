#pragma once

#include "password.hpp"
#include "passwordSaftyCheckerMock.hpp"
#include <gtest/gtest.h>

class Sut_Password : public ::testing::Test
{
public:
    Sut_Password() : validator(new PasswordSaftyCheckerMock)
    {
        sut = Password(validator);
    }
protected:
    std::shared_ptr<PasswordSaftyCheckerMock> validator;
    Password sut;
};

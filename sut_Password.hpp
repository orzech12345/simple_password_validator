#pragma once

#include "password.hpp"
#include "passwordSaftyCheckerMock.h"
#include <gtest/gtest.h>

#include <memory>



class Sut_Password : public ::testing::Test
{
public:
//    Sut_Password() : validator(new PasswordSaftyCheckerMock)
//    {
//        sut = Password(validator);
//    }
private:
    std::shared_ptr<PasswordSaftyCheckerMock> validator;
    Password sut;
};

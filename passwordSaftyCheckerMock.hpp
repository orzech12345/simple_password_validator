#pragma once

#include "abstractValidator.hpp"
#include <gmock/gmock.h>


class PasswordSaftyCheckerMock : public AbstractValidator
{
public:
    MOCK_CONST_METHOD1(isPasswordValid, bool(std::string));
};

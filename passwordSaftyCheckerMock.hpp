#pragma once

#include <gmock/gmock.h>

#include "abstractValidator.hpp"

class PasswordSaftyCheckerMock : public AbstractValidator
{
public:
    MOCK_CONST_METHOD1(isPasswordValid, bool(std::string));
    MOCK_CONST_METHOD1(isPasswordStrong, bool(std::string));
};

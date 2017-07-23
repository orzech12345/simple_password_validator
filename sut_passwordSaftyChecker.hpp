#pragma once

#include <gtest/gtest.h>
#include <passwordSaftyChecker.hpp>

class Sut_passwordSaftyChecker : public ::testing::Test
{
protected:
    PasswordSaftyChecker sut;
};

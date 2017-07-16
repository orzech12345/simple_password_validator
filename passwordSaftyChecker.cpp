#include "passwordSaftyChecker.hpp"

bool PasswordSaftyChecker::isPasswordValid(std::string str) const
{
    return !str.empty();
}

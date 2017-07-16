#pragma once

class PasswordSaftyChecker : public AbstractValidator
{
public:
    bool isValid(std::string s) const;
}

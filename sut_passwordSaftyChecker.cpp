#pragma once

#include "sut_passwordSaftyChecker.hpp"

TEST_F(Sut_passwordSaftyChecker, empty_password_should_raise_alarm){
    const std::string typedPassword = "";
    EXPECT_FALSE(sut.isPasswordValid(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, too_short_password_should_raise_alarm){
    const std::string typedPassword = "qwerty";
    EXPECT_FALSE(sut.isPasswordValid(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, too_long_password_isnt_as_bad_idea_as_too_short_but_in_this_case_it_should_raise_alarm) {
    const std::string typedPassword = "qwertyuiopasdfghjklzxcvbnm";
    EXPECT_FALSE(sut.isPasswordValid(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, mixed_upper_and_lower_cases_should_raise_alarm){
    const std::string typedPassword = "qWeRtYuI";
    EXPECT_FALSE(sut.isPasswordValid(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, mixed_numbers_and_lower_cases_should_raise_alarm){
    const std::string typedPassword = "q1e3t5u6";
    EXPECT_FALSE(sut.isPasswordValid(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, random_special_char_and_lower_cases_should_raise_alarm){
    const std::string specialChar = "$";
    const std::string typedPassword = "qwertyu" + specialChar;
    EXPECT_FALSE(sut.isPasswordValid(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, should_pass_if_used_at_least_two_diffrent_kind_of_char){
    const std::string upperCase = "G";
    const std::string specialChar = "@";
    const std::string typedPassword = upperCase+"qwerty"+specialChar;
    EXPECT_TRUE(sut.isPasswordValid(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, should_pass_if_used_at_least_two_diffrent_kind_of_char(number_and_special)){
    const std::string randomNumber = "6";
    const std::string specialChar = "@";
    const std::string typedPassword = randomNumber+"qwerty"+specialChar;
    EXPECT_TRUE(sut.isPasswordValid(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, should_pass_if_used_at_least_two_diffrent_kind_of_char(upperCase_and_number)){
    const std::string randomNumber = "6";
    const std::string upperCase = "G";
    const std::string typedPassword = randomNumber+"qwerty"+specialChar;
    EXPECT_TRUE(sut.isPasswordValid(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, should_fail_if_password_is_valid_but_not_safe_at_all){
    const std::string randomNumber = "6";
    const std::string specialChar = "@";
    const std::string typedPassword = randomNumber+"qwerty"+specialChar;
    EXPECT_FALSE(sut.isPasswordStrong(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, should_pass_if_password_is_strong_enought){
    const std::string randomNumber = "6";
    const std::string specialChar = "@";
    const std::string upperCase = "G"
    const std::string typedPassword = randomNumber+"qwe"+specialChar+"rty"+upperCase;
    EXPECT_TRUE(sut.isPasswordStrong(typedPassword));
}

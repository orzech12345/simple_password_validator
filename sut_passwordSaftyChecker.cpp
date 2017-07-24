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

TEST_F(Sut_passwordSaftyChecker, too_long_password_isnt_as_bad_idea_as_too_short_but_in_this_case_it_should_raise_alarm){
    const std::string typedPassword = "qwertyuiopasdfghjklzxcvbnm";
    EXPECT_FALSE(sut.isPasswordValid(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, too_few_diffrent_kind_of_char){
    const std::string specialChar = "$";
    const std::string typedPassword = "" + specialChar;
    EXPECT_FALSE(sut.isPasswordStrong(typedPassword))
}

TEST_F(Sut_passwordSaftyChecker, should_pass_if_contain_at_least_two_diffrent_kind_of_char){
    const std::string specialChar = "$";
    const std::string randomNumber = "5";

    const std::string typedPassword = "" + specialChar + randomNumber;
    EXPECT_TRUE(sut.isPasswordStrong(typedPassword));

    const std::string upperCase = "G";
    const std::string diffrentPassword = randomNumber + upperCase;
    EXPECT_TRUE(sut.isPasswordStrong(diffrentPassword));
}

TEST_F(Sut_passwordSaftyChecker, should_pass_if_password_is_really_strong_and_contain_three_diffrent_type_of_char){
    const std::string specialChar = "#";
    const std::string randomNumber = "6";
    const std::string upperCase = "G";

    const std::string typedPassword = specialChar + randomNumber + upperCase;
    EXPECT_TRUE(sut.isPasswordStrong(typedPassword));
}

TEST_F(Sut_passwordSaftyChecker, one_kind_of_char_mixed_with_lower_case_should_raise_alarm){
    const std::string upperChar = "G";
    const std::string typedPassword = upperChar + "qwerty" + upperChar;
    EXPECT_FALSE(sut.isPasswordValid(typedPassword));

    const std::string randomNumber = "6";
    const std::string diffrentPassword = randomNumber + "qwe" + randomNumber + "rty" + randomNumber;
    EXPECT_FALSE(sut.isPasswordValid(diffrentPassword));

    const std::string specialChar = "$";
    const std::string oddPassword = specialChar + "qwertyu" + specialChar;
    EXPECT_FALSE(sut.isPasswordValid(oddPassword));
}

TEST_F(Sut_passwordSaftyChecker, two_kind_of_chars_mixed_with_lower_case_should_pass){
    const std::string upperCase = "G";
    const std::string specialChar = "@";
    const std::string typedPassword = upperCase+"qwerty"+specialChar;
    EXPECT_TRUE(sut.isPasswordValid(typedPassword));

    const std::string randomNumber = "6";
    const std::string diffrentPassword = upperCase+"qwerty"+randomNumber;
    EXPECT_TRUE(sut.isPasswordValid(diffrentPassword));

    const std::string oddPassword = specialChar+"qwerty"+randomNumber;
    EXPECT_TRUE(sut.isPasswordValid(diffrentPassword));
}

TEST_F(Sut_passwordSaftyChecker, should_pass_if_password_is_really_strong){
    const std::string randomNumber = "6";
    const std::string specialChar = "@";
    const std::string upperCase = "G";
    const std::string typedPassword = randomNumber+"qwe"+specialChar+"rty"+upperCase;
    EXPECT_TRUE(sut.isPasswordStrong(typedPassword));
}

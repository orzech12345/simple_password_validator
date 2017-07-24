#include "sut_Password.hpp"

TEST_F(Sut_Password, validation_process_request_to_check_password)
{
    const std::string simplePassword = "qwertyuiop";

    EXPECT_CALL(*validator, isPasswordValid(simplePassword)).Times(1).WillOnce(
                ::testing::Return(true));

    sut.setValue(simplePassword);
    EXPECT_TRUE(sut.isPasswordValid());
}

TEST_F(Sut_Password, validation_process_request_to_decide_if_password_is_strong_or_not)
{
    const std::string simplePassword = "qwertyuiop";

    EXPECT_CALL(*validator, isPasswordStrong(simplePassword)).Times(1).WillOnce(
                ::testing::Return(true));

    sut.setValue(simplePassword);
    EXPECT_TRUE(sut.isPasswordStrong());
}

TEST_F(Sut_Password, should_be_easly_comparable)
{
    const std::string firstPassword {"ASDFG!2345"};
    const std::string secondPassword {"QWERTY!2345"};

    Password diffrentPassword;

    sut.setValue(firstPassword);
    diffrentPassword.setValue(firstPassword);
    EXPECT_EQ(sut, diffrentPassword);

    diffrentPassword.setValue(secondPassword);
    EXPECT_NE(sut, diffrentPassword);
}


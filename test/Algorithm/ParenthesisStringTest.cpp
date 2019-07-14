#include <Algorithm/ParenthesisString.hpp>

#include <string>

#include <gtest/gtest.h>

using namespace src::algo;

struct ParenthesisStringTest : public ::testing::Test
{
    ParenthesisStringTest(){}
    virtual ~ParenthesisStringTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    ParenthesisString impl_;
};

TEST_F(ParenthesisStringTest, TreatLowerAndUppercaseCharAsTheSame)
{
    std::string text = "ABabcdCDeFEf";

    auto result = impl_.compress(text);
    EXPECT_EQ(result.size(), 6u);
}

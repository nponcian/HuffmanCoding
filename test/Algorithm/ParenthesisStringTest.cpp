#include <Algorithm/ParenthesisStringAlgorithm.hpp>

#include <string>

#include <gtest/gtest.h>

using namespace src::algo;

struct ParenthesisStringAlgorithmTest : public ::testing::Test
{
    ParenthesisStringAlgorithmTest(){}
    virtual ~ParenthesisStringAlgorithmTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    ParenthesisStringAlgorithm impl_;
};

TEST_F(ParenthesisStringAlgorithmTest, TreatLowerAndUppercaseCharAsTheSame)
{
    std::string text = "ABabcdCDeFEf";

    auto result = impl_.compress(text);
    EXPECT_EQ(result.size(), 6u);
}

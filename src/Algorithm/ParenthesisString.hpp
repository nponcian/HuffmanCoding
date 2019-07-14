#ifndef SRC_ALGORITHM_PARENTHESISSTRING_HPP
#define SRC_ALGORITHM_PARENTHESISSTRING_HPP

#include <Algorithm/IAlgorithm.hpp>

namespace src::algo
{

class ParenthesisString : public IAlgorithm
{
public:
    ParenthesisString();

    virtual CharacterAndCodeMap compress(const std::string& text) override;
};

} // src::algo

#endif // SRC_ALGORITHM_PARENTHESISSTRING_HPP

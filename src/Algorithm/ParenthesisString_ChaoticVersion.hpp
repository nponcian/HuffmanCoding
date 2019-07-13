#ifndef SRC_ALGORITHM_PARENTHESISSTRING_CHAOTICVERSION_HPP
#define SRC_ALGORITHM_PARENTHESISSTRING_CHAOTICVERSION_HPP

#include <Algorithm/IAlgorithm.hpp>

namespace src::algo
{

// As the name suggests, the implementation of this class is totally CHAOTIC!
// And for the sake of authenticity, it will remain CHAOTIC! :)
class ParenthesisString_ChaoticVersion : public IAlgorithm
{
public:
    ParenthesisString_ChaoticVersion();

    virtual std::string compress(const std::string& text) override;
};

} // src::algo

#endif // SRC_ALGORITHM_PARENTHESISSTRING_CHAOTICVERSION_HPP

#ifndef SRC_ALGORITHM_PARENTHESISSTRINGALGORITHM_HPP
#define SRC_ALGORITHM_PARENTHESISSTRINGALGORITHM_HPP

#include <Algorithm/IAlgorithm.hpp>

namespace src::algo
{

class ParenthesisStringAlgorithm : public IAlgorithm
{
public:
    ParenthesisStringAlgorithm();

    virtual CharacterAndCodeMap compress(const std::string& text) override;
};

} // src::algo

#endif // SRC_ALGORITHM_PARENTHESISSTRINGALGORITHM_HPP

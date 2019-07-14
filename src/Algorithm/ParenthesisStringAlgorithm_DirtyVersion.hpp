#ifndef SRC_ALGORITHM_PARENTHESISSTRINGALGORITHM_DIRTYVERSION_HPP
#define SRC_ALGORITHM_PARENTHESISSTRINGALGORITHM_DIRTYVERSION_HPP

#include <Algorithm/IAlgorithm.hpp>

namespace src::algo
{

// As the name suggests, the implementation of this class is totally DIRTY!
// And for the sake of authenticity, it will remain DIRTY! :)
class ParenthesisStringAlgorithm_DirtyVersion : public IAlgorithm
{
public:
    ParenthesisStringAlgorithm_DirtyVersion();

    virtual CharacterAndCodeMap compress(const std::string& text) override;
};

} // src::algo

#endif // SRC_ALGORITHM_PARENTHESISSTRINGALGORITHM_DIRTYVERSION_HPP

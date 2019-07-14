#ifndef SRC_ALGORITHM_NODEALGORITHM_HPP
#define SRC_ALGORITHM_NODEALGORITHM_HPP

#include <Algorithm/IAlgorithm.hpp>

namespace src::algo
{

class NodeAlgorithm : public IAlgorithm
{
public:
    NodeAlgorithm();

    virtual CharacterAndCodeMap compress(const std::string& text) override;
};

} // src::algo

#endif // SRC_ALGORITHM_NODEALGORITHM_HPP

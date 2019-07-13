#ifndef SRC_IALGORITHM_HPP
#define SRC_IALGORITHM_HPP

#include <string>

namespace src::algo
{

class IAlgorithm
{
public:
    virtual ~IAlgorithm(){}
    virtual std::string compress(const std::string& text) = 0;
};

} // namespace src::algo

#endif // SRC_IALGORITHM_HPP

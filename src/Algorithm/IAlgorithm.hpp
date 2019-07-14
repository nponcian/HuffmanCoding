#ifndef SRC_IALGORITHM_HPP
#define SRC_IALGORITHM_HPP

#include <map>
#include <string>

namespace src::algo
{

using CharacterAndCodeMap = std::map<std::string, std::string>;

class IAlgorithm
{
public:
    virtual ~IAlgorithm(){}
    virtual CharacterAndCodeMap compress(const std::string& text) = 0;
};

} // namespace src::algo

#endif // SRC_IALGORITHM_HPP

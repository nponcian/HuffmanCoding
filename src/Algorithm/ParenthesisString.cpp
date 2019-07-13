#include <Algorithm/ParenthesisString.hpp>

#include <algorithm>
#include <map>
#include <vector>

#include <Common/Logger.hpp>

namespace src::algo
{
namespace
{

using CharacterAndFrequencyMap = std::map<std::string, unsigned>;
using CharacterAndFrequencyVec = std::vector<std::pair<std::string, unsigned>>;

common::Logger logger("ParenthesisString");

CharacterAndFrequencyMap mapCharactersToFrequency(const std::string& text)
{
    CharacterAndFrequencyMap chFreqMap;
    for (const auto& ch : text)
    {
        chFreqMap[std::string(1, ch)]++;
    }
    return chFreqMap;
}

CharacterAndFrequencyVec sortByMappedTypeValue(const CharacterAndFrequencyMap& chFreqMap)
{
    CharacterAndFrequencyVec chFreqVec;
    for (const auto& pair : chFreqMap)
    {
        chFreqVec.push_back(std::make_pair(pair.first, pair.second));
    }
    std::stable_sort(chFreqVec.begin(), chFreqVec.end(),
                    [](const auto& lhs, const auto& rhs)
                    {
                        return lhs.second < rhs.second;
                    });
    return chFreqVec;
}

template <typename T>
void printCharacterAndFrequency(const T& container)
{
    logger.print("Character\t\tFrequency");
    for (const auto& pair : container)
    {
        logger.print(pair.first, "\t\t\t", pair.second);
    }
}

void process(const CharacterAndFrequencyMap& chFreqMap)
{
    CharacterAndFrequencyVec chFreqVec = sortByMappedTypeValue(chFreqMap);
    printCharacterAndFrequency(chFreqVec);
}

} // namespace

ParenthesisString::ParenthesisString()
{
}

std::string ParenthesisString::compress(const std::string& text)
{
    CharacterAndFrequencyMap chFreqMap = mapCharactersToFrequency(text);
    printCharacterAndFrequency(chFreqMap);

    process(chFreqMap);


    logger.print();
    logger.print();
    logger.print();
    logger.print("Program by PONci");
    logger.print("|------    ---------     |\\      |");
    logger.print("|      |  |         |    | \\     |");
    logger.print("|      |  |  O  --  |    |  \\    |");
    logger.print("|------   |         |    |   \\   |");
    logger.print("|         |  \\___/  |    |    \\  |");
    logger.print("|          ---------     |     \\ |");
    logger.print("|                        |      \\|");

    return {};
}

} // src::algo

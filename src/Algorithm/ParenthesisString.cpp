#include <Algorithm/ParenthesisString.hpp>

#include <algorithm>
#include <map>
#include <set>
#include <vector>

#include <Common/Logger.hpp>

namespace src::algo
{
namespace
{

using CharacterAndFrequencyMap = std::map<std::string, unsigned>;
using CharacterAndFrequencyVec = std::vector<std::pair<std::string, unsigned>>;

common::Logger logger("ParenthesisString");

struct Node
{
    std::pair<std::string, unsigned> left;
    std::pair<std::string, unsigned> right;
};

CharacterAndFrequencyVec getCharacterToFrequencyPairs(const std::string& text)
{
    CharacterAndFrequencyMap chFreqMap;
    for (auto ch : text)
    {
        ch = std::tolower(ch);
        chFreqMap[std::string(1, ch)]++;
    }

    std::set<char> processedChars;
    CharacterAndFrequencyVec chFreqVec;
    for (const auto& ch : text)
    {
        if (processedChars.count(ch)) continue;

        processedChars.insert(ch);

        std::string chStr(1, ch);
        chFreqVec.push_back(std::make_pair(chStr, chFreqMap[chStr]));
    }

    return chFreqVec;
}

void sortByFrequency(CharacterAndFrequencyVec& chFreqVec)
{
    std::stable_sort(chFreqVec.begin(), chFreqVec.end(),
                    [](const auto& lhs, const auto& rhs)
                    {
                        return lhs.second < rhs.second;
                    });
}

template <typename T>
void printCharacterAndFrequency(const T& container)
{
    logger.print();
    logger.print("Character\t\tFrequency");
    for (const auto& pair : container)
    {
        logger.print(pair.first, "\t\t\t", pair.second);
    }
}

void combineFirstTwo(CharacterAndFrequencyVec& chFreqVec)
{
    if (chFreqVec.size() < 2u) return;

    auto& item0 = chFreqVec.at(0);
    auto& item1 = chFreqVec.at(1);

    auto [left, right] = (item0.second <= item1.second) ?
                            Node{item0, item1} :
                            Node{item1, item0};

    item0.first = "(" + left.first + right.first + ")";
    item0.second = item0.second + item1.second;
    chFreqVec.erase(chFreqVec.begin() + 1);
}

void processHuffmanTree(CharacterAndFrequencyVec& chFreqVec)
{
    if (chFreqVec.size() <= 1u) return;

    sortByFrequency(chFreqVec);
    printCharacterAndFrequency(chFreqVec);

    combineFirstTwo(chFreqVec);
    processHuffmanTree(chFreqVec);
}

void processHuffmanCode(const CharacterAndFrequencyVec&)
{
}

} // namespace

ParenthesisString::ParenthesisString()
{
}

std::string ParenthesisString::compress(const std::string& text)
{
    CharacterAndFrequencyVec chFreqVec = getCharacterToFrequencyPairs(text);
    printCharacterAndFrequency(chFreqVec);

    processHuffmanTree(chFreqVec);
    printCharacterAndFrequency(chFreqVec);
    processHuffmanCode(chFreqVec);
    printCharacterAndFrequency(chFreqVec);

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

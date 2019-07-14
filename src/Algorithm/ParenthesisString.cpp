#include <Algorithm/ParenthesisString.hpp>

#include <algorithm>
#include <map>
#include <stack>
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

bool isLetter(const char ch)
{
    return (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z');
}

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
    for (auto ch : text)
    {
        ch = std::tolower(ch);

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

void sortSingleCharsWithSameFrequencyByLetter(CharacterAndFrequencyVec& chFreqVec)
{
    std::stable_sort(chFreqVec.begin(), chFreqVec.end(),
                    [](const auto& lhs, const auto& rhs)
                    {
                        bool areBothSingleChars = (lhs.first.size() == 1u && rhs.first.size() == 1u);
                        bool areFrequenciesSame = (lhs.second == rhs.second);
                        bool shouldLetterBeFirst = (isLetter(lhs.first.front()) && !isLetter(rhs.first.front()));

                        return areBothSingleChars && areFrequenciesSame && shouldLetterBeFirst;
                    });
}

template <typename T>
void printContainerOfPairs(const T& container)
{
    static const unsigned FREQUENCY_OR_CODE_POSITION = 29u;

    logger.print();
    logger.print("Character                    Frequency / Code");
    for (const auto& pair : container)
    {
        std::string spaces = " ";
        unsigned stringSize = static_cast<unsigned>(pair.first.size());
        unsigned limit = FREQUENCY_OR_CODE_POSITION - std::min(FREQUENCY_OR_CODE_POSITION, stringSize);
        for (unsigned ctr = 1; ctr < limit; ctr++)
        {
            spaces = spaces + " ";
        }

        logger.print(pair.first, spaces, pair.second);
    }
}

void combineFirstTwo(CharacterAndFrequencyVec& chFreqVec)
{
    if (chFreqVec.size() < 2u) return;

    auto& item0 = chFreqVec.at(0);
    auto& item1 = chFreqVec.at(1);

    auto [left, right] = (item0.second <= item1.second) ?
                            std::make_pair(item0, item1) :
                            std::make_pair(item1, item0);

    item0.first = "(" + left.first + right.first + ")";
    item0.second = item0.second + item1.second;
    chFreqVec.erase(chFreqVec.begin() + 1); // Say hi to a lot of moving std::vector memories! :)
}

void buildHuffmanTree(CharacterAndFrequencyVec& chFreqVec)
{
    if (chFreqVec.size() <= 1u) return;

    sortByFrequency(chFreqVec);
    printContainerOfPairs(chFreqVec);

    combineFirstTwo(chFreqVec);
    buildHuffmanTree(chFreqVec);
}

std::string transformCode(std::stack<char> code)
{
    std::string transformed = "";
    while (!code.empty())
    {
        transformed = transformed + code.top();
        code.pop();
    }
    return {transformed.rbegin(), transformed.rend()};
}

CharacterAndCodeMap buildHuffmanCode(const std::string& huffmanTree)
{
    CharacterAndCodeMap chCodeMap;

    std::stack<char> code;
    for(const auto& ch : huffmanTree)
    {
        if (ch == '(')
        {
            code.push('0');
        }
        else if (ch == ')')
        {
            code.pop();
            if (!code.empty())
            {
                code.top() = '1';
            }
        }
        else
        {
            chCodeMap[std::string(1, ch)] = transformCode(code);
            code.top() = '1';
        }
    }

    return chCodeMap;
}

} // namespace

ParenthesisString::ParenthesisString()
{
}

CharacterAndCodeMap ParenthesisString::compress(const std::string& text)
{
    CharacterAndFrequencyVec chFreqVec = getCharacterToFrequencyPairs(text);

    sortByFrequency(chFreqVec);
    sortSingleCharsWithSameFrequencyByLetter(chFreqVec);
    printContainerOfPairs(chFreqVec);

    buildHuffmanTree(chFreqVec);
    printContainerOfPairs(chFreqVec);

    CharacterAndCodeMap chCodeMap;
    if (chFreqVec.size() == 1u)
    {
        chCodeMap = buildHuffmanCode(chFreqVec.front().first);
        printContainerOfPairs(chCodeMap);
    }

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
    logger.print();

    return chCodeMap;
}

} // src::algo

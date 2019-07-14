#include <Algorithm/NodeAlgorithm.hpp>

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

common::Logger logger("NodeAlgorithm");

} // namespace

NodeAlgorithm::NodeAlgorithm()
{
}

CharacterAndCodeMap NodeAlgorithm::compress(const std::string&)
{
    logger.print("Cooking...");

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

    return {};
}

} // src::algo

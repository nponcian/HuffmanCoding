#include <Controller.hpp>

#include <string>

#include <Algorithm/ParenthesisString_ChaoticVersion.hpp>
#include <Algorithm/IAlgorithm.hpp>
#include <Common/Logger.hpp>
#include <File/FileHandler.hpp>

namespace src
{
namespace
{

common::Logger logger("Controller");

} // namespace

Controller::Controller()
{
}

void Controller::handle(const std::string& input)
{
    if (input == "--help")
    {
    }
    else
    {
        auto text = file::readContentsOfFile(input);
        if (text.empty()) return;

        auto algorithms = createAlgorithms();
        for (const auto& algorithm : algorithms)
        {
            algorithm->compress(text);
        }
    }
}

std::vector<std::shared_ptr<algo::IAlgorithm>> Controller::createAlgorithms()
{
    return
        {
            std::make_unique<algo::ParenthesisString_ChaoticVersion>(),
        };
}

} // namespace src

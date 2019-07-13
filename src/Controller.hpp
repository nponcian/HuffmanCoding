#ifndef SRC_DISPATCHER_HPP
#define SRC_DISPATCHER_HPP

#include <memory>
#include <vector>

namespace src
{
namespace algo
{

class IAlgorithm;

} // namespace algo

class Controller
{
public:
    Controller();

    static void handle(const std::string& input);

private:
    static std::vector<std::shared_ptr<algo::IAlgorithm>> createAlgorithms();
};

} // namespace src

#endif // SRC_DISPATCHER_HPP

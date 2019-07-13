#include <iostream>

#include <Controller.hpp>
#include <Common/Logger.hpp>

namespace
{

src::common::Logger logger("main");

} // namespace

int main(int argc, char** argv)
{
    logger.print("Start of execution");

    if (argc == 2) src::Controller::handle(*(argv+1));
    else           src::Controller::handle("--help");

    logger.print("End of execution\n");
    return 0;
}

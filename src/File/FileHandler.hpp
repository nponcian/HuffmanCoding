#ifndef SRC_FILE_FILEHANDLER_HPP
#define SRC_FILE_FILEHANDLER_HPP

#include <string>

namespace src::file
{

std::string readContentsOfFile(const std::string& fileName);

void writeContentsToFile(
    const std::string& fileName,
    const std::string& contents);

} // namespace src::file

#endif // SRC_FILE_FILEHANDLER_HPP
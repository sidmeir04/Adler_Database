#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void LogToFile(const std::string &message)
{
    std::ofstream log_file("logs.txt", std::ios_base::app); // Open file in append mode
    if (log_file.is_open())
    {
        log_file << message << std::endl; // Write message to the log file
        log_file.close();                 // Close the file after writing
    }
}
#include "Logger.hpp"

Logger::Logger (const std::string &file) : _file(file) {}

Logger::~Logger () {}

void
Logger::log (std::string const &dest, std::string const &message) {

    void (Logger::*f)(const std::string &) const = (dest == "console" ? &Logger::logToConsole : &Logger::logToFile);
    (this->*f)(makeLogEntry(message));
}

void
Logger::logToConsole (const std::string &log) const {

    std::cout << log << std::endl;
}

void
Logger::logToFile (const std::string &log) const {

    std::ofstream ofs;
    ofs.open(this->_file, std::ios::app);

    if (!ofs.is_open()) {
        std::cout << "Coulnd't open file." << std::endl;
        return;
    }

    ofs << log << std::endl;
    ofs.close();
}

std::string
Logger::makeLogEntry (const std::string &message) const {

    time_t      now = time(0);
    std::string entry,
                timestamp = ctime(&now);

    timestamp[timestamp.length() - 1] = 0;
    entry = "[" + timestamp + "]: " + message;
    return entry;
}

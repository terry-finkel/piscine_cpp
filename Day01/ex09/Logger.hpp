#ifndef DAY01_EX09_LOGGER_HPP
# define DAY01_EX09_LOGGER_HPP

# include <fstream>
# include <iostream>

class Logger {

  public:
                Logger (const std::string &);
                ~Logger ();
    void        log (std::string const &, std::string const &);
    std::string makeLogEntry (const std::string &) const;

  private:
    std::string _file;
    void        logToConsole (const std::string &) const;
    void        logToFile (const std::string &) const;
};

#endif /* DAY01_EX09_LOGGER_HPP */

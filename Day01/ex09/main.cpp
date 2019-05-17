#include "Logger.hpp"

int
main () {

    Logger logger("file.logs");
    logger.log("console", "logs");
    logger.log("console", "trucs");
    logger.log("file", "foret");
    logger.log("console", "fromage");
    logger.log("file", "onion");
    logger.log("file", "sir friendzone");

    return 0;
}
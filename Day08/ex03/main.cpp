#include "IInstruction.hpp"
#include "Mindopen.hpp"
#include <iostream>

int
main (int argc, char const *argv[]) {

    if (argc == 1) {
        std::cout << "usage: " << std::string(argv[0]).substr(2) << " [file(s)]" << std::endl;
        return EXIT_SUCCESS;
    }

    for (int k = 1; k < argc; k++) {
        try {
            Mindopen mindopen(argv[k]);
        } catch (std::runtime_error &e) {
            std::cout << std::string(argv[0]).substr(2) << ": " << argv[k] << ": " << e.what() << std::endl;
        } catch (Mindopen::InvalidToken &e) {
            std::cout << std::string(argv[0]).substr(2) << ": " << argv[k] << ": " << e.what() << std::endl;
        }
    }

    return 0;
}

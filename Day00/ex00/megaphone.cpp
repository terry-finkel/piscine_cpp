#include <cctype>
#include <iostream>

int
main (int argc, const char *argv[]) {

    if (argc == 1) {
        std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int k = 1; k < argc;  k++) {
            std::string str(argv[k]);
            for (size_t p = 0; p < str.size(); p++) {
                str[p] = (char)toupper(str[p]);
            }
            std::cout << str;
        }
        std::cout << std::endl;
    }

    return 0;
}

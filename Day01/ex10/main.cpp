#include <fstream>
#include <iostream>
#include <sys/stat.h>

int
main (int argc, const char *argv[]) {

    int retcode = 0;

    if (argc == 1 || (argc == 2 && std::string(argv[1]) == "--")) {
        std::cout << std::cin.rdbuf();
    }

    for (int k = 1; k < argc; k++) {
        struct stat st;
        stat(argv[k], &st);
        if (S_ISDIR(st.st_mode)) {
            std::cout << argv[0] << ": " << argv[k] << ": Is a directory" << std::endl;
            retcode = 1;
            continue;
        } else if (S_ISFIFO(st.st_mode) || S_ISBLK(st.st_mode) || S_ISSOCK(st.st_mode) || S_ISCHR(st.st_mode)) {
            std::cout << argv[0] << ": " << argv[k] << ": Operation not permitted" << std::endl;
            retcode = 1;
            continue;
        }

        std::ifstream ifs;
        ifs.open(argv[k]);
        if (!ifs.is_open()) {
            std::cout << argv[0] << ": " << argv[k] << ": Error opening file" << std::endl;
            retcode = 1;
        } else {
            std::cout << ifs.rdbuf();
            ifs.close();
        }
    }

    return retcode;
}

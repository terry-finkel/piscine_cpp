#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

int
main (int argc, const char *argv[]) {

    if (argc != 4) {
        std::cout << argv[0] << ": usage: replace <file> <string_to_be_replaced> <string_to_replace_with>" << std::endl;
        return -1;
    }

    if (!strlen(argv[2]) || !strlen(argv[3])) {
        std::cout << argv[0] << ": cannot take empty strings" << std::endl;
        return -1;
    }

    std::fstream file;
    file.open(argv[1], std::fstream::in);
    if (!file.is_open()) {
        std::cout << argv[0] << ": couldn't open file" << std::endl;
        return -1;
    }

    std::ostringstream oss;
    oss << file.rdbuf();
    std::string buff = oss.str();

    const size_t replaceLength = strlen(argv[2]);
    size_t pos = 0;
    for (;;) {
        if ((pos = buff.find(argv[2], pos)) == std::string::npos)
            break;
        buff.replace(pos, replaceLength, argv[3]);
    }

    std::fstream replace;
    std::string newFile(argv[1]);
    replace.open(newFile.append(".replace").c_str(), std::fstream::out);
    replace << buff;
    return 0;
}

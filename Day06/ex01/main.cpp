#include <cmath>
#include <iostream>

struct Data {
    std::string s1;
    int         n;
    std::string s2;
};

void *
serialize () {

    srand(time(0));
    std::string *buffer = new std::string;

    for (int k = 0; k < 17; k++) {
        if (k == 8) {
            *buffer += std::to_string(rand());
            continue;
        }

        char c;
        do {
            c = rand() % 127;
        } while (!isalnum(c));
        *buffer += c;
    }

    std::cout << "Serializing: " << *buffer << std::endl;

    return buffer;
}

Data *
deserialize (void *raw) {

    std::string *str = reinterpret_cast<std::string *>(raw);
    Data        *data = new Data;

    data->s1 = str->substr(0, 8);
    data->s2 = str->substr(str->length() - 8);

    str->replace(str->length() - 8, 8, 8, '\0');
    data->n = std::stoi(str->substr(8).c_str());

    return data;
}

int
main () {

    Data *data = deserialize(serialize());

    std::cout << "Structure data:" << std::endl;
    std::cout << "  std::string s1 = \"" << data->s1 << "\"" << std::endl;
    std::cout << "  int         n = " << data->n << std::endl;
    std::cout << "  std::string s2 = \"" << data->s2 << "\"" << std::endl;

    return 0;
}

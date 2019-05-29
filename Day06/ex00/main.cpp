#include "Scalar.hpp"

int
main (int argc, char const *argv[]) {

    if (argc == 2) {
        Scalar scalar(argv[1]);
        scalar.display();
    }

    return 0;
}

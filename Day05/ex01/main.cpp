#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int
main () {

    Bureaucrat b1("Joker", 1);
    Bureaucrat b2("Harley", 7);
    Form f1("AHAHAH", 1, 1);
    Form f2("Daddy!", 15, 15);

    std::cout << b2 << " is trying to sign " << f1 << "." << std::endl;
    b2.signForm(f1);

    std::cout << b2 << " is trying to sign " << f2 << "." << std::endl;
    b2.signForm(f2);

    std::cout << b1 << " is trying to sign " << f1 << "." << std::endl;
    b1.signForm(f1);

    std::cout << b1 << " is trying to sign " << f2 << "." << std::endl;
    b1.signForm(f2);

    return 0;
}

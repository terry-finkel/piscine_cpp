#include "Bureaucrat.hpp"
#include <iostream>

int
main () {

    try {
        Bureaucrat b("Alfred", 151);
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    } try {
        Bureaucrat b("Batman", 0);
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } try {
        Bureaucrat b("Robin", 149);
        std::cout << "Hello " << b;
        b.decGrade();
        std::cout << "Hello " << b;
        b.decGrade();
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    } try {
        Bureaucrat b("Harvey", 2);
        std::cout << "Hello " << b;
        b.incGrade();
        std::cout << "Hello " << b;
        b.incGrade();
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

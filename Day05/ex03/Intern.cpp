#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &rhs) { *this = rhs; }

Intern::~Intern() {}

Intern &
Intern::operator=(Intern const &) {

    return *this;
}

Form *
Intern::makeForm(std::string name, std::string target) {

    Form *form = NULL;

    if (name == "presidential pardon") {
        form = new PresidentialPardonForm(target);
    } else if (name == "robotomy request") {
        form = new RobotomyRequestForm(target);
    } else if (name == "shrubbery creation") {
        form = new ShrubberyCreationForm(target);
    }

    if (form) {
        std::cout << "Intern creates " << form->getName() << std::endl;
    } else {
        std::cout << name << " form isn't known, could not create it." << std::endl;
    }

    return form;
}

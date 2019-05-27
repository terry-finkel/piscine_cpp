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

const char *
Intern::UnknownForm::what() const throw() {

    return "unknown form";
}

Form *
Intern::makeForm(std::string name, std::string target) throw(UnknownForm) {

    Form *form = NULL;

    if (name == "presidential pardon") {
        form = new PresidentialPardonForm(target);
    } else if (name == "robotomy request") {
        form = new RobotomyRequestForm(target);
    } else if (name == "shrubbery creation") {
        form = new ShrubberyCreationForm(target);
    }

    if (form) {
        std::cout << "Intern creates " << form->getName() << "." << std::endl;
        return form;
    }

    throw Intern::UnknownForm();
}

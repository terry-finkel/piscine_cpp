#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("presidential pardon", target, 5, 25) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) { *this = rhs; }

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {

    Form::operator=(rhs);
    return *this;
}

void
PresidentialPardonForm::execute(Bureaucrat const &executor) const {

    Form::execute(executor);
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

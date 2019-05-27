#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomy request", target, 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) { *this = rhs; }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {

    Form::operator=(rhs);
    return *this;
}

void
RobotomyRequestForm::execute(Bureaucrat const &executor) const {

    Form::execute(executor);

    std::cout << "* Drilling noises * ";
    srand(time(0));
    if (rand() % 2) {
        std::cout << getTarget() << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomization has failed..." << std::endl;
    }
}

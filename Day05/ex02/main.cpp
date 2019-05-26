#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int
main () {

    Bureaucrat batman("Batman", 1);
    Bureaucrat alfred("Alfred", 150);
    PresidentialPardonForm ppf("Harvey");
    RobotomyRequestForm rrf("Joker");
    ShrubberyCreationForm scf("Batcave");

    batman.executeForm(ppf);
    batman.executeForm(rrf);
    batman.executeForm(scf);

    batman.signForm(ppf);
    batman.signForm(rrf);
    batman.signForm(scf);

    batman.executeForm(ppf);
    batman.executeForm(rrf);
    batman.executeForm(scf);

    alfred.executeForm(ppf);
    alfred.executeForm(rrf);
    alfred.executeForm(scf);

    return 0;
}

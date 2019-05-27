#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int
main () {

    Bureaucrat batman("Batman", 1);
    Bureaucrat alfred("Alfred", 150);
    Form *ppf = new PresidentialPardonForm("Harvey");
    Form *rrf = new RobotomyRequestForm("Joker");
    Form *scf = new ShrubberyCreationForm("Batcave");

    batman.executeForm(*ppf);
    batman.executeForm(*rrf);
    batman.executeForm(*scf);

    batman.signForm(*ppf);
    batman.signForm(*rrf);
    batman.signForm(*scf);

    batman.executeForm(*ppf);
    batman.executeForm(*rrf);
    batman.executeForm(*scf);

    alfred.executeForm(*ppf);
    alfred.executeForm(*rrf);
    alfred.executeForm(*scf);

    delete ppf;
    delete rrf;
    delete scf;
    return 0;
}

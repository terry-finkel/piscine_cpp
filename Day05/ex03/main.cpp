#include "Bureaucrat.hpp"
#include "Intern.hpp"

int
main () {

    Bureaucrat batman("Batman", 1);
    Bureaucrat alfred("Alfred", 150);
    Intern slave;
    Form *ppf = slave.makeForm("presidential pardon", "Harvey");
    Form *rrf = slave.makeForm("robotomy request", "Joker");
    Form *scf = slave.makeForm("shrubbery creation", "Batcave");

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

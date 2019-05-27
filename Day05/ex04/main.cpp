#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int
main () {

    OfficeBlock gothamCommissary;
    Bureaucrat gordon("Gordon", 1);
    Bureaucrat harvey("Harvey", 150);
    Intern slave;

    gothamCommissary.doBureaucracy("presidential pardon", "Robin");

    gothamCommissary.setIntern(&slave);
    gothamCommissary.setSigningBureaucrat(&harvey);
    gothamCommissary.setExecutingBureaucrat(&gordon);

    gothamCommissary.doBureaucracy("eat shit and die", "Joker");
    gothamCommissary.doBureaucracy("presidential pardon", "Robin");

    return 0;
}

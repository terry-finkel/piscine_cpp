#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include <iostream>

OfficeBlock::OfficeBlock() : _executingBureaucrat(NULL), _intern(NULL), _signingBureaucrat(NULL) {}

OfficeBlock::OfficeBlock(Intern *i, Bureaucrat *eB, Bureaucrat *sB) :   _executingBureaucrat(eB),
                                                                        _intern(i),
                                                                        _signingBureaucrat(sB) {}

OfficeBlock::OfficeBlock(OfficeBlock const &rhs) { *this = rhs; }

OfficeBlock::~OfficeBlock() {}

OfficeBlock &
OfficeBlock::operator=(OfficeBlock const &) { return *this; }

void
OfficeBlock::doBureaucracy(std::string const &name, std::string const &target) const {

    std::cout << "Requesting form " << name << " on " << target << "..." << std::endl;

    if (getExecutingBureaucrat() == NULL || getIntern() == NULL || getSigningBureaucrat() == NULL) {

        if (getIntern() == NULL)
            std::cout << "Block " << this << " doesn't have an intern." << std::endl;
        if (getSigningBureaucrat() == NULL)
            std::cout << "Block " << this << " doesn't have a signing bureaucrat." << std::endl;
        if (getExecutingBureaucrat() == NULL)
            std::cout << "Block " << this << " doesn't have an executing bureaucrat." << std::endl;

        return;
    }

    Form *form;
    try {
        form = getIntern()->makeForm(name, target);
    } catch (Intern::UnknownForm &e) {
        std::cout << "Could not create form: " << e.what() << " (\"" << name << "\")" << "." << std::endl;
        return;
    }

    try {
        getSigningBureaucrat()->signForm(*form);
    } catch (Form::) {
        delete form;
    }

    delete form;
}

Bureaucrat*
OfficeBlock::getExecutingBureaucrat() const { return _executingBureaucrat; }

Intern*
OfficeBlock::getIntern() const { return _intern; }

Bureaucrat*
OfficeBlock::getSigningBureaucrat() const { return _signingBureaucrat; }

void
OfficeBlock::setExecutingBureaucrat(Bureaucrat *b) { _executingBureaucrat = b; }

void
OfficeBlock::setIntern(Intern *i) { _intern = i; }

void
OfficeBlock::setSigningBureaucrat(Bureaucrat *b) { _signingBureaucrat = b; }

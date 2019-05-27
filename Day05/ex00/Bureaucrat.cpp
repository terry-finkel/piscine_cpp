#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const name, int grade) throw(GradeTooHighException, GradeTooLowException)
    : _grade(grade), _name(name) {

    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) { *this = rhs; }

Bureaucrat::~Bureaucrat() {}

Bureaucrat &
Bureaucrat::operator=(Bureaucrat const &rhs) {

    _grade = rhs.getGrade();
    return *this;
}

const char *
Bureaucrat::GradeTooHighException::what() const throw( ) {

    return "grade too high";
}

const char *
Bureaucrat::GradeTooLowException::what() const throw( ) {

    return "grade too low";
}

void
Bureaucrat::decGrade() throw(GradeTooLowException) {

    if (_grade == 150) throw Bureaucrat::GradeTooLowException();

    _grade += 1;
}

int
Bureaucrat::getGrade() const {

    return _grade;
}

std::string const
Bureaucrat::getName() const {

    return _name;
}

void
Bureaucrat::incGrade() throw(GradeTooHighException) {

    if (_grade == 1) throw Bureaucrat::GradeTooHighException();

    _grade -= 1;
}

std::ostream &
operator<<(std::ostream &os, Bureaucrat const &b) {

    std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return os;
}

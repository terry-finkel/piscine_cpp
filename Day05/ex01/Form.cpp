#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(std::string const name, int const execGrade, int const signGrade) :  _execGrade(execGrade),
                                                                                _name(name),
                                                                                _signed(false),
                                                                                _signGrade(signGrade) {}

Form::Form(Form const &rhs) :   _execGrade(rhs.getExecGrade()),
                                _name(rhs.getName()),
                                _signGrade(rhs.getSignGrade()) { *this = rhs; }

Form &
Form::operator=(Form const &rhs) {

    _signed = rhs.getSigned();
    return *this;
}

const char *
Form::GradeTooHighException::what() const throw() {

    return "Grade too high";
}

const char *
Form::GradeTooLowException::what() const throw() {

    return "Grade too low";
}

void
Form::beSigned(Bureaucrat const &b) throw(GradeTooLowException) {

    if (getSignGrade() < b.getGrade()) throw Form::GradeTooLowException();

    _signed = true;
}

int
Form::getExecGrade() const {

    return _execGrade;
}

std::string const
Form::getName() const {

    return _name;
}

bool
Form::getSigned() const {

    return _signed;
}

int
Form::getSignGrade() const {

    return _signGrade;
}

std::ostream &
operator<<(std::ostream &os, Form const &f) {

    std::cout << "Form " << f.getName() << ", sign grade " << f.getSignGrade() << ", exec grade " << f.getExecGrade()
        << "," << (f.getSigned() ? "" : " not") << " signed";
    return os;
}

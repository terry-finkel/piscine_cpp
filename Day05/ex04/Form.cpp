#include "Form.hpp"

Form::Form() : _execGrade(0), _signGrade(0) {}

Form::Form(std::string const name, std::string const target, int const execGrade, int const signGrade)
                                                                                :   _execGrade(execGrade),
                                                                                    _name(name),
                                                                                    _signed(false),
                                                                                    _signGrade(signGrade),
                                                                                    _target(target) {}

Form::Form(Form const &rhs) :   _execGrade(rhs.getExecGrade()),
                                _name(rhs.getName()),
                                _signGrade(rhs.getSignGrade()) { *this = rhs; }

Form::~Form() {}

Form &
Form::operator=(Form const &rhs) {

    _signed = rhs.getSigned();
    _target = rhs.getTarget();
    return *this;
}

const char *
Form::GradeTooHighException::what() const throw() {

    return "grade too high";
}

const char *
Form::GradeTooLowException::what() const throw() {

    return "grade too low";
}

const char *
Form::NotSignedException::what() const throw() {

    return "form not signed";
}

void
Form::beSigned(Bureaucrat const &b) throw(Bureaucrat::GradeTooLowException) {

    if (getSignGrade() < b.getGrade()) throw Bureaucrat::GradeTooLowException();

    _signed = true;
}

void
Form::execute(Bureaucrat const &executor) const throw (Bureaucrat::GradeTooLowException) {

    if (!getSigned()) throw Form::NotSignedException();
    if (getExecGrade() < executor.getGrade()) throw Bureaucrat::GradeTooLowException();
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

std::string
Form::getTarget() const {

    return _target;
}

std::ostream &
operator<<(std::ostream &os, Form const &f) {

    std::cout << "Form " << f.getName() << ", sign grade " << f.getSignGrade() << ", exec grade " << f.getExecGrade()
        << "," << (f.getSigned() ? "" : " not") << " signed";
    return os;
}

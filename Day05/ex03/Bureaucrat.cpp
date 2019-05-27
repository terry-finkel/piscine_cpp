#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    if (getGrade() == 150) throw Bureaucrat::GradeTooLowException();

    _grade += 1;
}

void
Bureaucrat::executeForm(Form const &f) const {

    try {
        std::cout << getName() << " executes " << f.getName() << "." << std::endl;
        f.execute(*this);
    } catch (Form::NotSignedException &e) {
        std::cout << "Failed to execute " << f.getName() << ": " << e.what() << "." << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << "Failed to execute " << f.getName() << ": " << e.what() << "." << std::endl;
    }
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

    if (getGrade() == 1) throw Bureaucrat::GradeTooHighException();

    _grade -= 1;
}

void
Bureaucrat::signForm(Form &f) {

    if (f.getSigned()) {
        std::cout << getName() << " cannot sign " << f.getName() << " because: form already signed" << "." << std::endl;
    } else {
        try {
            f.beSigned(*this);
            std::cout << getName() << " signs " << f.getName() << "." << std::endl;
        } catch (Form::GradeTooLowException &e) {
            std::cout << getName() << " cannot sign " << f.getName() << " because: " << e.what() << "." << std::endl;
        }
    }
}

std::ostream &
operator<<(std::ostream &os, Bureaucrat const &b) {

    std::cout << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

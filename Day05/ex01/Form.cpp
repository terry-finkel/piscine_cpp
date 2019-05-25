#include "Form.hpp"

Form::Form(std::string const name, int const execGrade, int const signGrade) {}

Form::Form(Form const &rhs) { *this = rhs; }

Form &
Form::operator=(Form const &rhs) {

    _signed = rhs.getSigned();
    return *this;
}

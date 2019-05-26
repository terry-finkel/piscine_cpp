#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubbery creation", target, 137, 145) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) { *this = rhs; }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {

    Form::operator=(rhs);
    return *this;
}

void
ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

    Form::execute(executor);

    std::string name = getTarget();
    name += "_shrubbery";

    std::ofstream ofs(name);
    if (!ofs.is_open()) {
        std::cout << name << ": error opening file." << std::endl;
        return;
    }

    ofs << "       _-_              _-_\n"
           "    /~~   ~~\\        /~~   ~~\\\n"
           " /~~         ~~\\  /~~         ~~\\\n"
           "{               }{               }\n"
           " \\  _-     -_  /  \\  _-     -_  /\n"
           "   ~  \\\\ //  ~      ~  \\\\ //  ~\n"
           "_- -   | | _- _  _- -   | | _- _\n"
           "  _ -  | |   -_    _ -  | |   -_\n"
           "      // \\\\            // \\\\" << std::endl;
    ofs.close();
}

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include <iostream>

class Intern {
public:
            Intern();
            Intern(Intern const &);
    virtual ~Intern();
    Intern  &operator=(Intern const &);
    Form    *makeForm(std::string, std::string);
};

#endif /* INTERN_HPP */

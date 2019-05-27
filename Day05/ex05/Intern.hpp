#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include <iostream>

class Intern {
public:
                    Intern();
                    Intern(Intern const &);
    virtual         ~Intern();
    Intern          &operator=(Intern const &);

    class UnknownForm : public std::exception {
    public:
        const char  *what() const throw();
    };

    Form            *makeForm(std::string, std::string) throw(UnknownForm);
};

#endif /* INTERN_HPP */

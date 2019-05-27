#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form {
private:
    int const           _execGrade;
    std::string const   _name;
    bool                _signed;
    int const           _signGrade;
    std::string         _target;

protected:
                        Form();

public:
                        Form(std::string, std::string, int, int);
                        Form(Form const &);
    virtual             ~Form();
    Form                &operator=(Form const &);

    class NotSignedException : public std::exception {
    public:
        const char       *what() const throw();
    };

    void                beSigned(Bureaucrat const &);
    virtual void        execute(Bureaucrat const &) const;
    int                 getExecGrade() const;
    std::string const   getName() const;
    bool                getSigned() const;
    int                 getSignGrade() const;
    std::string         getTarget() const;
};

std::ostream            &operator<<(std::ostream &, Form const &);

#endif /* FORM_HPP */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form {
private:
    int const           _execGrade;
    std::string const   _name;
    bool                _signed;
    int const           _signGrade;

public:
                        Form(std::string, int, int);
                        Form(Form const &);
    virtual             ~Form();
    Form                &operator=(Form const &);

    class GradeTooHighException : public std::exception {
    public:
        const char      *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char      *what() const throw();
    };

    void                beSigned(Bureaucrat const &) throw(GradeTooLowException);
    int                 getExecGrade() const;
    std::string const   getName() const;
    bool                getSigned() const;
    int                 getSignGrade() const;
};

std::ostream            &operator<<(std::ostream &, Form const &);

#endif /* FORM_HPP */

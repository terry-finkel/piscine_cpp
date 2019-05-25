#ifndef DAY05_EX01_FORM_HPP
# define DAY05_EX01_FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Form {
private:
    int const           _execGrade;
    std::string const   _name;
    bool                _signed;
    int const           _signGrade;

public:
                        Form( std::string, int, int );
                        Form( Form const & );
    virtual             ~Form( );
    Form                &operator=( Form const &);

    class GradeTooHighException : public std::exception {
    public:
        const char      *what( ) throw( );
    };

    class GradeTooLowException : public std::exception {
    public:
        const char      *what( ) throw( );
    };

    void                beSigned( Bureaucrat const & ) throw( );
    int const           getExecGrade( ) const;
    std::string const   getName( ) const;
    bool                getSigned( ) const;
    int const           getSignGrade( ) const;
};

std::ostream            &operator<<( std::ostream &, Form const & );

#endif /* DAY05_EX01_FORM_HPP */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat {
private:
                        Bureaucrat( ) {};
    int                 _grade;
    std::string const   _name;

public:
                        Bureaucrat( std::string, int ) throw( GradeTooHighException, GradeTooLowException );
                        Bureaucrat( Bureaucrat const & );
    virtual             ~Bureaucrat( ) {};
    Bureaucrat          &operator=( Bureaucrat const & );

    class GradeTooHighException : public std::exception {
    public:
        const char      *what( ) const throw( );
    };

    class GradeTooLowException : public std::exception {
    public:
        const char      *what( ) const throw( );
    };

    void                decGrade( ) throw( GradeTooLowException );
    int                 getGrade( ) const;
    std::string const   getName( ) const;
    void                incGrade( ) throw( GradeTooHighException );
};

std::ostream            &operator<<( std::ostream &, Bureaucrat const & );

#endif /* BUREAUCRAT_HPP */

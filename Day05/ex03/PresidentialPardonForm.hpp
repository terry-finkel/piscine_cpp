#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <iostream>

class PresidentialPardonForm : public Form {
private:
                            PresidentialPardonForm();

public:
    explicit                PresidentialPardonForm(std::string);
                            PresidentialPardonForm(PresidentialPardonForm const &);
    virtual                 ~PresidentialPardonForm();
    PresidentialPardonForm  &operator=(PresidentialPardonForm const &);
    void                    execute(Bureaucrat const &) const throw(GradeTooLowException, NotSignedException);
};

#endif /* PRESIDENTIALPARDONFORM_HPP */

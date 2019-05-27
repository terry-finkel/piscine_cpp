#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <iostream>

class RobotomyRequestForm : public Form {
private:
                        RobotomyRequestForm();

public:
    explicit            RobotomyRequestForm(std::string);
                        RobotomyRequestForm(RobotomyRequestForm const &);
    virtual             ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm const &);
    void                execute(Bureaucrat const &) const throw(GradeTooLowException, NotSignedException);
};

#endif /* ROBOTOMYREQUESTFORM_HPP */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <iostream>

class ShrubberyCreationForm : public Form {
private:
                            ShrubberyCreationForm();

public:
    explicit                ShrubberyCreationForm(std::string);
                            ShrubberyCreationForm(ShrubberyCreationForm const &);
    virtual                 ~ShrubberyCreationForm();
    ShrubberyCreationForm   &operator=(ShrubberyCreationForm const &);
    void                    execute(Bureaucrat const &) const;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */

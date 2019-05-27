#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <iostream>

class Bureaucrat;
class Intern;

class OfficeBlock {
private:
    Bureaucrat      *_executingBureaucrat;
    Intern          *_intern;
    Bureaucrat      *_signingBureaucrat;
                    OfficeBlock(OfficeBlock const &);
    OfficeBlock     &operator=(OfficeBlock const &);

public:
                    OfficeBlock();
                    OfficeBlock(Intern *, Bureaucrat *, Bureaucrat *);
    virtual         ~OfficeBlock();
    void            doBureaucracy(std::string const &, std::string const &) const;
    Bureaucrat      *getExecutingBureaucrat() const;
    Intern          *getIntern() const;
    Bureaucrat      *getSigningBureaucrat() const;
    void            setExecutingBureaucrat(Bureaucrat *);
    void            setIntern(Intern *);
    void            setSigningBureaucrat(Bureaucrat *);
};

#endif /* OFFICEBLOCK_HPP */

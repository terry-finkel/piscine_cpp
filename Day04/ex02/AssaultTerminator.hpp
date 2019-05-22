#ifndef DAY04_EX02_ASSAULTTERMINATOR_HPP
# define DAY04_EX02_ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {

public:
                        AssaultTerminator();
                        AssaultTerminator(AssaultTerminator const &);
    virtual             ~AssaultTerminator();
    AssaultTerminator   &operator=(AssaultTerminator const &);
    void                battleCry() const;
    ISpaceMarine        *clone() const;
    void                meleeAttack() const;
    void                rangedAttack() const;
};

#endif /* DAY04_EX02_ASSAULTTERMINATOR_HPP */

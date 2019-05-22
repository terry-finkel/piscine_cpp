#ifndef DAY04_EX02_TACTICALMARINE_HPP
# define DAY04_EX02_TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

  public:
                    TacticalMarine();
                    TacticalMarine(TacticalMarine const &);
    virtual         ~TacticalMarine();
    TacticalMarine  &operator=(TacticalMarine const &);
    void            battleCry() const;
    ISpaceMarine    *clone() const;
    void            meleeAttack() const;
    void            rangedAttack() const;
};

#endif /* DAY04_EX02_TACTICALMARINE_HPP */

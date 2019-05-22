#ifndef DAY04_EX02_ISPACEMARINE_HPP
# define DAY04_EX02_ISPACEMARINE_HPP

class ISpaceMarine {

  public:
    virtual                 ~ISpaceMarine() {};
    virtual void            battleCry() const = 0;
    virtual ISpaceMarine    *clone() const = 0;
    virtual void            meleeAttack() const = 0;
    virtual void            rangedAttack() const = 0;
};

#endif /* DAY04_EX02_ISPACEMARINE_HPP */

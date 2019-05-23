#ifndef DAY_04_EX03_AMATERIA_HPP
# define DAY_04_EX03_AMATERIA_HPP

# include <string>

# define MAX (4)

class ICharacter;

class AMateria {

  public:
    explicit            AMateria(std::string const &);
                        AMateria(AMateria const &);
    virtual             ~AMateria();
    AMateria            &operator=(AMateria const &);
    virtual AMateria    *clone() const = 0;
    std::string const   &getType();
    void                addXP(unsigned int);
    unsigned int        getXP() const;
    void                setXP(unsigned int);
    virtual void        use(ICharacter &) = 0;

  private:
    std::string         _type;
    unsigned int        _xp;
};

#endif /* DAY_04_EX03_AMATERIA_HPP */

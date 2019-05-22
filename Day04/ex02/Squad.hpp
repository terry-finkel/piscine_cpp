#ifndef DAY04_EX02_SQUAD_HPP
# define DAY04_EX02_SQUAD_HPP

# include "ISpaceMarine.hpp"
# include "ISquad.hpp"

class Squad : public ISquad {

  public:
                        Squad();
                        Squad(Squad const &);
    virtual             ~Squad();
    Squad               &operator=(Squad const &);
    int                 getCount() const;
    ISpaceMarine        *getUnit(int) const;
    int                 push(ISpaceMarine *);

  private:
    typedef struct      s_list   {
        ISpaceMarine    *unit;
        struct s_list   *next;
    }                   unit_t;
    int                 _count;
    unit_t              *_units;
    unit_t              *_getLastLink() const;
};

#endif /* DAY04_EX02_SQUAD_HPP */

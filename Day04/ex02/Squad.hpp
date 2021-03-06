#ifndef DAY04_EX02_SQUAD_HPP
# define DAY04_EX02_SQUAD_HPP

# include "ISpaceMarine.hpp"
# include "ISquad.hpp"

class Squad : public ISquad {

  private:
    typedef struct      s_list   {
        ISpaceMarine    *unit;
        struct s_list   *next;
    }                   unit_t;
    int                 _count;
    unit_t              *_head;
    unit_t              *_tail;
    void                _deleteSquad();

  public:
                        Squad();
                        Squad(Squad const &);
    virtual             ~Squad();
    Squad               &operator=(Squad const &);
    int                 getCount() const;
    ISpaceMarine        *getUnit(int) const;
    int                 push(ISpaceMarine *);
};

#endif /* DAY04_EX02_SQUAD_HPP */

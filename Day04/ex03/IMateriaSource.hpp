#ifndef DAY_04_EX03_IMATERIASOURCE_HPP
# define DAY_04_EX03_IMATERIASOURCE_HPP

# include "AMateria.hpp"
# include <string>

class IMateriaSource {

  public:
    virtual             ~IMateriaSource() {};
    virtual AMateria    *createMateria(std::string const &) = 0;
    virtual void        learnMateria(AMateria *) = 0;
};

#endif /* DAY_04_EX03_IMATERIASOURCE_HPP */

#ifndef DAY_04_EX03_MATERIASOURCE_HPP
# define DAY_04_EX03_MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource {

  private:
    AMateria        *_sources[MAX];
    void            _deleteSources();

  public:
                    MateriaSource();
                    MateriaSource(MateriaSource const &);
    virtual         ~MateriaSource();
    MateriaSource   &operator=(MateriaSource const &);
    AMateria        *createMateria(std::string const &);
    void            learnMateria(AMateria *);
};

#endif /* DAY_04_EX03_MATERIASOURCE_HPP */

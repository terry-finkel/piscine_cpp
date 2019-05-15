#ifndef DAY01_EX05_HUMAN_HPP
# define DAY01_EX05_HUMAN_HPP

# include "Brain.hpp"

class Human {

  public:
                Human ();
                ~Human ();
    const Brain &getBrain() const;
    std::string identify() const;

  private:
    const Brain _brain;
};

#endif /* DAY01_EX05_HUMAN_HPP */

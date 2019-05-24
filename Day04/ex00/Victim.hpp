#ifndef DAY04_EX00_VICTIM_HPP
# define DAY04_EX00_VICTIM_HPP

# include <string>

class Victim {

  private:
    std::string     _name;

  protected:
                    Victim() {};

  public:
                    Victim(std::string);
                    Victim(Victim const &);
    virtual         ~Victim();
    Victim          &operator=(Victim const &);
    std::string     getName() const;
    virtual void    getPolymorphed() const;
};

std::ostream    &operator<<(std::ostream &, Victim const &);

#endif /* DAY04_EX00_VICTIM_HPP */

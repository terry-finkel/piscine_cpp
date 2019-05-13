#ifndef DAY01_EX00_PONY_HPP
# define DAY01_EX00_PONY_HPP

# include <iostream>

class Pony {

  public:
    Pony (std::string &, int, int);
    ~Pony ();
    void run () const;

  private:
    int         _heads,
                _legs;
    std::string _type;
};

#endif /* DAY01_EX00_PONY_HPP */

#ifndef DAY02_EX00_FIXED_CLASS_HPP
# define DAY02_EX00_FIXED_CLASS_HPP

# include <iostream>

class Fixed {

  public:
                        Fixed ();
    explicit            Fixed (float);
    explicit            Fixed (int);
                        Fixed (Fixed const &f);
                        ~Fixed ();
    Fixed               &operator = (Fixed const &);
    int                 getRawBits () const;
    void                setRawBits (int);
    float               toFloat () const;
    int                 toInt () const;

  private:
    static int const    _WIDTH;
    int                 _value;
};

std::ostream            &operator << (std::ostream &, Fixed const &);

#endif /* DAY02_EX00_FIXED_CLASS_HPP */

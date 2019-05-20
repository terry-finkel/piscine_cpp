#ifndef DAY02_EX00_FIXED_CLASS_HPP
# define DAY02_EX00_FIXED_CLASS_HPP

# include <iostream>

class Fixed {

  public:
                        Fixed ();
    explicit            Fixed (float);
    explicit            Fixed (int);
                        Fixed (Fixed const &f);
    virtual             ~Fixed ();
    Fixed               &operator = (Fixed const &);
    bool                operator > (Fixed const &) const;
    bool                operator < (Fixed const &) const;
    bool                operator >= (Fixed const &) const;
    bool                operator <= (Fixed const &) const;
    bool                operator == (Fixed const &) const;
    bool                operator != (Fixed const &) const;
    Fixed               operator + (Fixed const &) const;
    Fixed               operator - (Fixed const &) const;
    Fixed               operator * (Fixed const &) const;
    Fixed               operator / (Fixed const &) const;
    Fixed               &operator ++ ();
    Fixed const         operator ++ (int);
    Fixed               &operator -- ();
    Fixed const         operator -- (int);
    int                 getRawBits () const;
    static Fixed        &max (Fixed &, Fixed &);
    static Fixed const  &max (Fixed const &, Fixed const &);
    static Fixed        &min (Fixed &, Fixed &);
    static Fixed const  &min (Fixed const &, Fixed const &);
    void                setRawBits (float);
    void                setRawBits (int);
    float               toFloat () const;
    int                 toInt () const;

  private:
    static int const    _WIDTH;
    int                 _value;
};

std::ostream            &operator << (std::ostream &, Fixed const &);

#endif /* DAY02_EX00_FIXED_CLASS_HPP */

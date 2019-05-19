#ifndef DAY02_EX00_FIXED_CLASS_HPP
# define DAY02_EX00_FIXED_CLASS_HPP

class Fixed {

  public:
                        Fixed ();
    explicit            Fixed (Fixed const &f);
                        ~Fixed ();
    Fixed               &operator = (Fixed const &);
    int                 getRawBits () const;
    void                setRawBits (int const);

  private:
    static const int    _WIDTH;
    int                 _value;
};

#endif /* DAY02_EX00_FIXED_CLASS_HPP */

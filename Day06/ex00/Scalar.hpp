#ifndef SCALAR_HPP
# define SCALAR_HPP

class Scalar {
private:
                Scalar();
    char        _asChar;
    double      _asDouble;
    float       _asFloat;
    int         _asInt;
    bool        _impossibleC;
    bool        _impossibleD;
    bool        _impossibleF;
    bool        _impossibleI;

public:
    explicit    Scalar(char const *);
                Scalar(Scalar const &);
    virtual     ~Scalar();
    Scalar      &operator=(Scalar const &);
    void        display() const;
    void        setAsDouble(double);
    void        setAsFloat(double);
    void        setImpossibleD(bool);
    void        setImpossibleF(bool);
};

#endif /* SCALAR_HPP */

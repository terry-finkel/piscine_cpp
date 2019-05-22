#ifndef DAY04_EX01_ENEMY_HPP
# define DAY04_EX01_ENEMY_HPP

# include <string>

class Enemy {

  public:
                    Enemy(int, std::string const &);
                    Enemy(Enemy const &);
    virtual         ~Enemy();
    Enemy           &operator=(Enemy const &);
    int             getHP() const;
    std::string     getType() const;
    virtual void    takeDamage(int);

  protected:
                    Enemy();
    int             _HP;
    std::string     _type;
};

#endif /* DAY04_EX01_POWERFIST_HPP */

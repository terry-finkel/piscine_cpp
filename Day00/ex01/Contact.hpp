#ifndef DAY00_EX01_CONTACT_HPP
# define DAY00_EX01_CONTACT_HPP

# include <string>

class Contact {

  public:
    static int entries;
    std::string getFirstName () const;
    std::string getLastName () const;
    std::string getNickname () const;
    std::string getLogin () const;
    std::string getPostalAddress () const;
    std::string getEmailAddress () const;
    std::string getPhoneNumber () const;
    std::string getBirthdayDate () const;
    std::string getFavoriteMeal () const;
    std::string getUnderwearColor () const;
    std::string getDarkestSecret () const;
    void outputDetails () const;
    static void outputList (Contact contacts[]);
    void setFirstName (std::string &);
    void setLastName (std::string &);
    void setNickname (std::string &);
    void setLogin (std::string &);
    void setPostalAddress (std::string &);
    void setEmailAddress (std::string &);
    void setPhoneNumber (std::string &);
    void setBirthdayDate (std::string &);
    void setFavoriteMeal (std::string &);
    void setUnderwearColor (std::string &);
    void setDarkestSecret (std::string &);

  private:
    std::string _firstName,
                _lastName,
                _nickname,
                _login,
                _postalAddress,
                _emailAddress,
                _phoneNumber,
                _birthdayDate,
                _favoriteMeal,
                _underwearColor,
                _darkestSecret;
    static void outputRow (int index, std::string, std::string, std::string);
};

# endif /* DAY00_EX01_CONTACT_HPP */

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
    void setFirstName (std::string &str);
    void setLastName (std::string &str);
    void setNickname (std::string &str);
    void setLogin (std::string &str);
    void setPostalAddress (std::string &str);
    void setEmailAddress (std::string &str);
    void setPhoneNumber (std::string &str);
    void setBirthdayDate (std::string &str);
    void setFavoriteMeal (std::string &str);
    void setUnderwearColor (std::string &str);
    void setDarkestSecret (std::string &str);

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
    static void outputRow (int index, std::string firstName, std::string lastName, std::string nickname);

};

# endif /* DAY00_EX01_CONTACT_HPP */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>

std::string
Contact::getFirstName (void) const {

    return this->_firstName;
}

std::string
Contact::getLastName (void) const {

    return this->_lastName;
}

std::string
Contact::getNickname (void) const {

    return this->_nickname;
}

std::string
Contact::getLogin (void) const {

    return this->_login;
}

std::string
Contact::getPostalAddress (void) const {

    return this->_postalAddress;
}

std::string
Contact::getEmailAddress (void) const {

    return this->_emailAddress;
}

std::string
Contact::getPhoneNumber (void) const {

    return this->_phoneNumber;
}

std::string
Contact::getBirthdayDate (void) const {

    return this->_birthdayDate;
}

std::string
Contact::getFavoriteMeal (void) const {

    return this->_favoriteMeal;
}

std::string
Contact::getUnderwearColor (void) const {

    return this->_underwearColor;
}

std::string
Contact::getDarkestSecret (void) const {

    return this->_darkestSecret;
}

void
Contact::outputDetails (void) const {

    std::cout << "FIRST NAME: " << this->getFirstName() << std::endl << "LAST NAME: " << this->getLastName()
    << std::endl << "NICKNAME: " << this->getNickname() << std::endl << "LOGIN: " << this->getLogin() << std::endl
    << "POSTAL ADDRESS: " << this->getPostalAddress() << std::endl << "EMAIL ADDRESS: " << this->getEmailAddress()
    << std::endl << "PHONE NUMBER: " << this->getPhoneNumber() << std::endl << "BIRTHDAY DATE: "
    << this->getBirthdayDate() << std::endl << "FAVORITE MEAL: " << this->getFavoriteMeal() << std::endl
    << "UNDERWEAR COLOR: " << this->getUnderwearColor() << std::endl << "DARKEST SECRET: " << this->getDarkestSecret()
    << std::endl;
}

void
Contact::outputList (Contact contacts[]) {

    std::cout << "   index  |first name| last name| nickname " << std::endl;
    for (int k = 0; k < Contact::entries; k++) {
        Contact::outputRow(k, contacts[k].getFirstName(), contacts[k].getLastName(), contacts[k].getNickname());
    }
}

void
Contact::outputRow (int index, std::string firstName, std::string lastName, std::string nickname) {

    if (firstName.length() > 10) {
        firstName = firstName.substr(0, 10);
        firstName[9] = '.';
    }
    if (lastName.length() > 10) {
        lastName = lastName.substr(0, 10);
        lastName[9] = '.';
    }
    if (nickname.length() > 10) {
        nickname = nickname.substr(0, 10);
        nickname[9] = '.';
    }

    std::cout << std::setw(10) << index << "|" << std::setw(10) << firstName << "|" << std::setw(10) << lastName
    << "|" << std::setw(10) << nickname << std::endl;
}

void
Contact::setFirstName (std::string str) {

    this->_firstName = str;
}

void
Contact::setLastName (std::string str) {

    this->_lastName = str;
}

void
Contact::setNickname (std::string str) {

    this->_nickname = str;
}

void
Contact::setLogin (std::string str) {

    this->_login = str;
}

void
Contact::setPostalAddress (std::string str) {

    this->_postalAddress = str;
}

void
Contact::setEmailAddress (std::string str) {

    this->_emailAddress = str;
}

void
Contact::setPhoneNumber (std::string str) {

    this->_phoneNumber = str;
}

void
Contact::setBirthdayDate (std::string str) {

    this->_birthdayDate = str;
}

void
Contact::setFavoriteMeal (std::string str) {

    this->_favoriteMeal = str;
}

void
Contact::setUnderwearColor (std::string str) {

    this->_underwearColor = str;
}

void
Contact::setDarkestSecret (std::string str) {

    this->_darkestSecret = str;
}

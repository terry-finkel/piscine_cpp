#include "Contact.hpp"
#include <iostream>

#define MAX_ENTRIES 8
#define VOICE "**robotic voice** "
#define EMO_VOICE "**emotive robotic voice** "
#define HAPPY_VOICE "**happy robotic voice** "
#define SAD_VOICE "**sad robotic voice** "

int Contact::entries = 0;

Contact
createNewContact (void) {

    Contact     newContact;
    std::string buffer;

    std::cout << VOICE << "YES, FRIEND. I'M LISTENING, FRIEND. TELL ME IT'S FIRST NAME, FRIEND:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setFirstName(buffer);
    std::cout << VOICE << "TELL ME IT'S LAST NAME:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setLastName(buffer);
    std::cout << VOICE << "TELL ME IT'S NICKNAME:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setNickname(buffer);
    std::cout << VOICE << "TELL ME IT'S LOGIN:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setLogin(buffer);
    std::cout << VOICE << "TELL ME IT'S POSTAL ADDRESS:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setPostalAddress(buffer);
    std::cout << VOICE << "TELL ME IT'S EMAIL ADDRESS:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setEmailAddress(buffer);
    std::cout << VOICE << "TELL ME IT'S PHONE NUMBER:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setPhoneNumber(buffer);
    std::cout << VOICE << "TELL ME IT'S BIRTHDAY DATE:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setBirthdayDate(buffer);
    std::cout << VOICE << "TELL ME IT'S FAVORITE MEAL:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setFavoriteMeal(buffer);
    std::cout << VOICE << "TELL ME IT'S UNDERWEAR COLOR:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setUnderwearColor(buffer);
    std::cout << VOICE << "TELL ME IT'S DARKEST SECRET:" << std::endl;
    std::getline(std::cin, buffer);
    newContact.setDarkestSecret(buffer);
    std::cout << HAPPY_VOICE << "OKAY FRIEND! IT'S ALL IN THERE! WHAT ELSE CAN I DO FOR YOU FRIEND?" << std::endl;
    return newContact;
}

int
main (void) {

    Contact contacts[MAX_ENTRIES];

    std::cout << "*robotic voice* HELLO, FRIEND. PLEASE ENTER YOUR QUERY, FRIEND. I'M TOTALLY NOT A ROBOT, FRIEND."
    << std::endl;

    for (;;) {
        std::string buff;
        std::getline(std::cin, buff);

        if (buff == "EXIT") break;

        if (buff == "ADD") {
            if (Contact::entries == MAX_ENTRIES) {
                std::cout << SAD_VOICE << "MY STORAGE UNIT... ERR, I MEAN MY MEMORY IS FULL, FRIEND. I CAN'T REMEMBER "
                                          "ANY ADDITIONAL ENTRY. BECAUSE I'M TOTALLY NOT A ROBOT, FRIEND." << std::endl;
                continue;
            }
            contacts[Contact::entries] = createNewContact();
            Contact::entries += 1;
        } else if (buff == "SEARCH") {
            if (Contact::entries == 0) {
                std::cout << SAD_VOICE << "I DON'T THINK I HAVE ANYTHING TO TELL YOU FRIEND..." << std::endl;
                continue;
            }
            std::cout << VOICE << "YES FRIEND, HERE ARE THE PEOPLE I KNOW SO FAR:" << std::endl;
            Contact::outputList(contacts);
            for (;;) {
                std::cout << VOICE << "SELECT THE INDEX OF THE ENTRY YOU'D LIKE TO BE DISPLAYED:" << std::endl;
                std::getline(std::cin, buff);

                if (buff == "EXIT") goto EXIT;

                if (buff.length() == 1 && isdigit(buff[0])) {
                    int chosenEntry = buff[0] - '0';
                    if (chosenEntry < Contact::entries) {
                        contacts[chosenEntry].outputDetails();
                        std::cout << HAPPY_VOICE << "THERE YOU GO! ANYTHING ELSE I CAN DO FOR YOU FRIEND?" << std::endl;
                        break;
                    }
                }
                std::cout << VOICE << "I DIDN'T FIND THIS ENTRY FRIEND!" << std::endl;
            }
        } else {
            std::cout << VOICE << "QUERY NOT RECOGNIZED. WOULD YOU LIKE A SANDWICH FRIEND?" << std::endl;
        }
    }

    EXIT:
    std::cout << EMO_VOICE << "GOODBYE, FRIEND..." << std::endl;
    return 0;
}

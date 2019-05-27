#include "Bureaucrat.hpp"
#include "CentralBureaucracy.hpp"

#define GOTHAM_PEOPLE 150

std::string bureaucrats[] = {
        "Batman",
        "Joker",
        "Alfred",
        "Dick Grayson",
        "Catwoman",
        "Harvey Dent",
        "Harley Quinn",
        "Riddler",
        "Poison Ivy",
        "Scarecrow",
        "James Gordon",
        "Two-Face",
        "Barbara Gordon",
        "Bane",
        "Ra's Al Ghul",
        "Mr. Freeze",
        "Jason Todd",
        "Penguin",
        "Tim Drake",
        "Deadshot",
        "Talia al Ghul",
        "Deathstroke"
};

int
main () {

    CentralBureaucracy central;

    for (unsigned long k = 0; k < sizeof(bureaucrats) / sizeof(bureaucrats[0]); k++) {
        central.feed(new Bureaucrat(bureaucrats[k], (rand() % 150) + 1));
    }

    for (int k = 0; k < GOTHAM_PEOPLE; k++) {
        char buffer[11];
        buffer[0] = (rand() % 26) + 'A';
        for (int k = 1; k < 8; k++) {
            buffer[k] = (rand() % 26) + 'a';
        }
        for (int k = 8; k < 10; k++) {
            buffer[k] = (rand() % 10) + '0';
        }
        buffer[10] = '\0';
        central.queueUp(buffer);
    }

    for (;;) {}

    return 0;
}

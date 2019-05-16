#include "Human.hpp"

Human::Human () {}

Human::~Human () {}

void
Human::action (std::string const &action_name, std::string const &target) {

    const int   actions = 3;
    void        (Human::*f[actions])(std::string const &) = {
            &Human::meleeAttack,
            &Human::rangedAttack,
            &Human::intimidatingShout
    };
    std::string action[actions] = {
            "meleeAttack",
            "rangedAttack",
            "intimidatingShout"
    };

    for (int k = 0; k < actions; k++) {
        if (action_name == action[k]) return (this->*f[k])(target);
    }
}

void
Human::meleeAttack (std::string const &target) {

    std::cout << "Melee attack on " << target << " !" << std::endl;
}

void
Human::rangedAttack (std::string const &target) {

    std::cout << "Ranged attack on " << target << " !" << std::endl;
}

void
Human::intimidatingShout (std::string const &target) {

    std::cout << "Intimidating shout on " << target << " !" << std::endl;
}

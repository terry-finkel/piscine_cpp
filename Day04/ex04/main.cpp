#include "AsteroBocal.hpp"
#include "BocalSteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "MiningBarge.hpp"
#include "StripMiner.hpp"
#include <iostream>

int
main () {

    IAsteroid* asteroBocal = new AsteroBocal();
    IAsteroid* bocalSteroid = new BocalSteroid();

    IMiningLaser* deepCore = new DeepCoreMiner();
    IMiningLaser* strip = new StripMiner();
    IMiningLaser* stripBis = new StripMiner();
    IMiningLaser* stripTer = new StripMiner();

    MiningBarge* miningBarge = new MiningBarge();

    std::cout << "DeepCoreMiner mining " << asteroBocal->getName() << std::endl;
    deepCore->mine(asteroBocal);

    std::cout << std::endl << "DeepCoreMiner mining " << bocalSteroid->getName() << std::endl;
    deepCore->mine(bocalSteroid);

    std::cout << std::endl << "StripMiner mining " << asteroBocal->getName() << std::endl;
    strip->mine(asteroBocal);

    std::cout << std::endl << "StripMiner mining " << bocalSteroid->getName() << std::endl;
    strip->mine(bocalSteroid);

    std::cout << std::endl << "Lets equip MiningBarge with 2 weapons" << std::endl;
    miningBarge->equip(deepCore);
    miningBarge->equip(strip);

    std::cout << std::endl << "MINE MICROSOFT DEVELOPERS !" << std::endl;
    miningBarge->mine(asteroBocal);

    std::cout << std::endl << "Lets copy the mining barge to dig more and more AsteroBocal" << std::endl;
    MiningBarge anotherMiningBarge(*miningBarge);
    anotherMiningBarge.mine(asteroBocal);

    std::cout << std::endl << "Lets assign a new mining barge, equip it and dig this shit" << std::endl;
    MiningBarge assignMiningBarge = anotherMiningBarge;
    assignMiningBarge.equip(stripBis);
    assignMiningBarge.equip(stripTer);
    assignMiningBarge.mine(asteroBocal);

    delete asteroBocal;
    delete bocalSteroid;
    delete deepCore;
    delete strip;
    delete stripBis;
    delete stripTer;
    delete miningBarge;

    return 0;
}

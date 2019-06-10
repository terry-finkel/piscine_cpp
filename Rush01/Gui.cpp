#include "Gui.hpp"

sf::RenderWindow Gui::window(sf::VideoMode(320, 440), "ft_gkrellm");

Gui::Gui() {

}

Gui::Gui(Gui const &rhs) { *this = rhs; }

Gui::~Gui() {}

Gui &
Gui::operator=(Gui const &) {

    return *this;
}

void
Gui::render() {

    sf::RenderWindow& window = Gui::window;

    sf::Font font;
        if (!font.loadFromFile("assets/arial.ttf")) {
        // error...
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        OHName *oh_name = dynamic_cast<OHName*>(Monitor::getCurrent()->getModule(0));
        sf::RectangleShape shapea(sf::Vector2f(300, 80));
        shapea.setPosition(10, 10);
        shapea.setFillColor(sf::Color::Black);
        shapea.setFillColor(sf::Color(96, 99, 104));
        sf::Text text1a;
        sf::Text text2a;
        sf::Text text3a;
        sf::Text text4a;
        text1a.setFont(font);
        text2a.setFont(font);
        text3a.setFont(font);
        text4a.setFont(font);
        text1a.setString("Hostname");
        text2a.setString(oh_name->getHostname().c_str());
        text3a.setString("Username");
        text4a.setString(oh_name->getUsername().c_str());
        text1a.setPosition(20, 20);
        text2a.setPosition(140, 20);
        text3a.setPosition(20, 50);
        text4a.setPosition(140, 50);
        text1a.setFillColor(sf::Color::White);
        text2a.setFillColor(sf::Color::White);
        text3a.setFillColor(sf::Color::White);
        text4a.setFillColor(sf::Color::White);
        text1a.setCharacterSize(20);
        text2a.setCharacterSize(20);
        text3a.setCharacterSize(20);
        text4a.setCharacterSize(20);



        Time *time = dynamic_cast<Time*>(Monitor::getCurrent()->getModule(3));

        sf::RectangleShape shapeb(sf::Vector2f(300, 80));
        shapeb.setPosition(10, 110);
        shapeb.setFillColor(sf::Color(96, 99, 104));
        sf::Text text1b;
        sf::Text text2b;
        sf::Text text3b;
        sf::Text text4b;
        text1b.setFont(font);
        text2b.setFont(font);
        text3b.setFont(font);
        text4b.setFont(font);
        text1b.setString("Date");
        text2b.setString(time->getDate().c_str());
        text3b.setString("Time");
        text4b.setString(time->getTime().c_str());
        text1b.setPosition(20, 120);
        text2b.setPosition(140, 120);
        text3b.setPosition(20, 150);
        text4b.setPosition(140, 150);
        text1b.setFillColor(sf::Color::White);
        text2b.setFillColor(sf::Color::White);
        text3b.setFillColor(sf::Color::White);
        text4b.setFillColor(sf::Color::White);

        text1b.setCharacterSize(20);
        text2b.setCharacterSize(20);
        text3b.setCharacterSize(20);
        text4b.setCharacterSize(20);

        OsInfo *os_info = dynamic_cast<OsInfo*>(Monitor::getCurrent()->getModule(1));
        sf::RectangleShape shapec(sf::Vector2f(300, 110));
        shapec.setPosition(10, 210);
        shapec.setFillColor(sf::Color(96, 99, 104));
        sf::Text text1c;
        sf::Text text2c;
        sf::Text text3c;
        sf::Text text4c;
        sf::Text text5c;
        sf::Text text6c;
        text1c.setFont(font);
        text2c.setFont(font);
        text3c.setFont(font);
        text4c.setFont(font);
        text5c.setFont(font);
        text6c.setFont(font);
        text1c.setString("Machine");
        text2c.setString(os_info->getMachine().c_str());
        text3c.setString("Release");
        text4c.setString(os_info->getRelease().c_str());
        text5c.setString("Sysname");
        text6c.setString(os_info->getSysname().c_str());
        text1c.setPosition(20, 220);
        text2c.setPosition(140, 220);
        text3c.setPosition(20, 250);
        text4c.setPosition(140, 250);
        text5c.setPosition(20, 280);
        text6c.setPosition(140, 280);
        text1c.setFillColor(sf::Color::White);
        text2c.setFillColor(sf::Color::White);
        text3c.setFillColor(sf::Color::White);
        text4c.setFillColor(sf::Color::White);
        text5c.setFillColor(sf::Color::White);
        text6c.setFillColor(sf::Color::White);
        text1c.setCharacterSize(20);
        text2c.setCharacterSize(20);
        text3c.setCharacterSize(20);
        text4c.setCharacterSize(20);
        text5c.setCharacterSize(20);
        text6c.setCharacterSize(20);




        CpuUsage *  cpu_usage = dynamic_cast<CpuUsage*>(Monitor::getCurrent()->getModule(4));

        sf::Text cpu_txt;
        cpu_txt.setString("Cpu");
        cpu_txt.setFont(font);
        cpu_txt.setPosition(20, 330);
        cpu_txt.setCharacterSize(16);
        cpu_txt.setFillColor(sf::Color::White);

        sf::RectangleShape cputotal(sf::Vector2f(300, 10));
        sf::RectangleShape cpuuser(sf::Vector2f(cpu_usage->getUser() * 3, 10));
        sf::RectangleShape cpuused(sf::Vector2f(cpu_usage->getCPU() * 3, 10));

        cputotal.setPosition(10, 360);
        cpuuser.setPosition(10, 360);
        cpuused.setPosition(10, 360);

        cputotal.setFillColor(sf::Color(68, 70, 74));
        cpuuser.setFillColor(sf::Color(0, 132, 9));
        cpuused.setFillColor(sf::Color(255, 231, 7));

        Ram *       ram = dynamic_cast<Ram*>(Monitor::getCurrent()->getModule(5));

        sf::Text ram_txt;
        ram_txt.setString("Ram");
        ram_txt.setFont(font);
        ram_txt.setPosition(20, 380);
        ram_txt.setCharacterSize(16);
        ram_txt.setFillColor(sf::Color::White);

        sf::RectangleShape ramtotal(sf::Vector2f(300, 10));
        sf::RectangleShape ramuser(sf::Vector2f((ram->getSizeUsed()* 300) / ram->getSizeMax(), 10));

        ramtotal.setPosition(10, 410);
        ramuser.setPosition(10, 410);

        ramtotal.setFillColor(sf::Color(68, 70, 74));
        ramuser.setFillColor(sf::Color(0, 132, 9));



        window.clear(sf::Color(35, 36, 39));

        window.draw(shapea);
        window.draw(text1a);
        window.draw(text2a);
        window.draw(text3a);
        window.draw(text4a);


        window.draw(shapeb);
        window.draw(text1b);
        window.draw(text2b);
        window.draw(text3b);
        window.draw(text4b);

        window.draw(cputotal);
        window.draw(cpuused);
        window.draw(cpuuser);
        window.draw(cpu_txt);

        window.draw(ramtotal);
        window.draw(ramuser);
        window.draw(ram_txt);

        window.draw(shapec);
        window.draw(text1c);
        window.draw(text2c);
        window.draw(text3c);
        window.draw(text4c);
        window.draw(text5c);
        window.draw(text6c);


        window.display();
        sleep(sf::seconds(1));
        Monitor::getCurrent()->update();
    }
}

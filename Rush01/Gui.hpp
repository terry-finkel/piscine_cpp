#ifndef GUI_HPP
# define GUI_HPP

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"
# include <vector>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>

#include "OsInfo.hpp"
#include "OHName.hpp"
#include "ProcessList.hpp"
#include "Time.hpp"
#include "CpuUsage.hpp"
#include "Ram.hpp"

class Gui : public IMonitorDisplay {

public:
static sf::RenderWindow window;

                Gui();
                Gui(Gui const &);
    virtual     ~Gui();
    Gui         &operator=(Gui const &);
    void        render();
};

#endif /* GUI_HPP */

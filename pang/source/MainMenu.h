//
// Created by Alessandro Lira on 2019-04-20.
//

#ifndef PANG_MAINMENU_H
#define PANG_MAINMENU_H

#include "stdafx.h"


class MainMenu {

public:
    enum MenuResult{Nothing, Exit, Play};

    struct MenuItem {
    public:
        sf::Rect<int> rect;
        MenuResult action;
    };

    MenuResult show(sf::RenderWindow &window);

private:
    MenuResult getMenuResponse(sf::RenderWindow& window);
    MenuResult handleClick(int x, int y);
    std::vector<MenuItem> _menuItems;
};

#endif //PANG_MAINMENU_H

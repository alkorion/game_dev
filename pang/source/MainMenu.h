//
// Created by Alessandro Lira on 2019-04-20.
//

#ifndef KANJI_KOMBAT_MAINMENU_H
#define KANJI_KOMBAT_MAINMENU_H

#include "stdafx.h"


class MainMenu {

public:
    enum MenuResult{Nothing, Exit, Play};

    struct MenuItem {
    public:
        sf::Rect<int> rect;
        MenuResult action;
    };

    MenuResult show(sf::RenderWindow& window);

private:
    MenuResult getMenuResponse(sf::RenderWindow& window);
    MenuResult handleClick(int x, int y);
    std::vector<MenuItem> _menuItems;
};

#endif //KANJI_KOMBAT_MAINMENU_H

#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <iomanip>
#include <string>

class Menu
{
    friend std::ostream &operator<<(std::ostream &os, const Menu &obj);
    public:
        virtual void display(std::ostream &os) const = 0;
        virtual char read_choice() const = 0;
        virtual ~Menu() = default;
};

#endif //_MENU_H_
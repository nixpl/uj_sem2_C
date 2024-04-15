#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

#include <iostream>
#include <iomanip>
#include <string>
#include "Menu.h"

class Main_Menu: public Menu 
{
    protected:
        
    public:
        virtual void display(std::ostream &os) const override;
        virtual char read_choice() const override;
};

#endif //_MAIN_MENU_H_
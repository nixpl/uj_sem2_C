#ifndef _OL_MENU_H_
#define _OL_MENU_H_

#include <iostream>
#include <iomanip>
#include <string>
#include "Menu.h"

class OL_Menu: public Menu 
{
    protected:
        
    public:
        virtual void display(std::ostream &os) const override;
        virtual char read_choice() const override;
};

#endif //_OL_MENU_H_
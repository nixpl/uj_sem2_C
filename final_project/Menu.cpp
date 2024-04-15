#include "Menu.h"

std::ostream &operator<<(std::ostream &os, const Menu &obj) 
{
    obj.display(os);
    return os;
}
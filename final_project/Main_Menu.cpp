#include "Main_Menu.h"

void Main_Menu::display(std::ostream &os) const
{
    std::cout << "--MAIN-MENU--------------------" << std::endl;
    std::cout << "press '1' to show Library table" << std::endl;
    std::cout << "press '2' to show On Loan table" << std::endl;
    std::cout << "press 'q' to quit" << std::endl;
    std::cout << "your choice: ";
}

char Main_Menu::read_choice() const
{
    std::string choice {"q"};
    std::cin >> choice;

    if(choice.size() > 1)
        return ' ';
    return choice.at(0);
}

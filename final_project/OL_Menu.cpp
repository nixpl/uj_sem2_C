#include "OL_Menu.h"

void OL_Menu::display(std::ostream &os) const
{
    std::cout << "--ON-LOAN-MENU------------------------" << std::endl;
    std::cout << "press '1' to sort by ID" << std::endl;
    std::cout << "press '2' to sort by book name" << std::endl;
    std::cout << "press '3' to sort by author" << std::endl;
    std::cout << "press '4' to sort by date of borrowing" << std::endl;
    std::cout << "press '5' to sort by date of return" << std::endl;
    std::cout << "press '6' to reverse list" << std::endl;
    std::cout << "press '7' to return book" << std::endl;
    std::cout << "press 'r' to return to main menu" << std::endl;
    std::cout << "your choice: ";
}

char OL_Menu::read_choice() const
{
    std::string choice {"q"};
    std::cin >> choice;

    if(choice.size() > 1)
        return ' ';
    return choice.at(0);
}
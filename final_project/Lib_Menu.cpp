#include "Lib_Menu.h"

void Lib_Menu::display(std::ostream &os) const
{
    std::cout << "--LIBRARY-MENU------------------" << std::endl;
    std::cout << "press '1' to sort by ID" << std::endl;
    std::cout << "press '2' to sort by book name" << std::endl;
    std::cout << "press '3' to sort by author" << std::endl;
    std::cout << "press '4' to show only available" << std::endl;
    std::cout << "press '5' to show all" << std::endl;
    std::cout << "press '6' to reverse list" << std::endl;
    std::cout << "press '7' to add new book" << std::endl;
    std::cout << "press '8' to lend a book" << std::endl;
    std::cout << "press '9' to remove from Library" << std::endl;
    std::cout << "press 'r' to return to main menu" << std::endl;
    std::cout << "your choice: ";
}

char Lib_Menu::read_choice() const
{
    std::string choice {"q"};
    std::cin >> choice;

    if(choice.size() > 1)
        return ' ';
    return choice.at(0);
}
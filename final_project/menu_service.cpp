#include "menu_service.h"

void menu_f(std::vector<Book*> &library, std::vector<Book*> &on_loan)
{
    const Main_Menu main_menu;
    const Lib_Menu lib_menu;
    const OL_Menu ol_menu;

    char choice {' '};
    while(choice != 'q' && choice != 'Q')
    {
        std::cout << std::endl << main_menu;
        choice = main_menu.read_choice();
        switch(choice)
        {
            case '1': // press '1' to enter the library menu
                lib_menu_f(lib_menu, library, on_loan); //!!! przekazywać do tych funkcji odpowiednie vektory ze wskaznikami na klase !!!
                break;
            case '2': // press '2' to enter the on loan menu
                ol_menu_f(ol_menu, library, on_loan);
                break;
            case 'Q': // press 'q' to quit
            case 'q':
                break;
            default:
                std::cout << "unknow choice" << std::endl;           
        }
    }
}

void lib_menu_f(const Lib_Menu &lib_menu, std::vector<Book*> &library, std::vector<Book*> &on_loan)
{
    bool show_unavailable = true;
    char choice {' '};
    while(choice != 'r' && choice != 'R')
    {
        load_library(library);
        print_library(library, show_unavailable);

        std::cout << std::endl << lib_menu;
        choice = lib_menu.read_choice();
        switch(choice)
        {
            case '1':
                sort_by_id(library);
                break;
            case '2':
                sort_by_name(library);
                break;
            case '3':
                sort_by_author(library);
                break;
            case '4':
                show_unavailable = false;
                break;
            case '5':
                show_unavailable = true;
                break;
            case '6':
                std::reverse(library.begin(), library.end());
                break;
            case '7':
                add_to_library(library);
                break;
            case '8':
                lend_book(library, on_loan);
                break;
            case '9':
                remove_from_library(library);
                break;
            case 'R':
            case 'r':
                break; //breaking from this loop
            default:
                std::cout << "unknow choice" << std::endl;            
        }
        save_vec(library, "lib_data.txt");
        save_vec(on_loan, "ol_data.txt");
    }
}

void ol_menu_f(const OL_Menu &ol_menu, std::vector<Book*> &library, std::vector<Book*> &on_loan)
{
    char choice {' '};
    while(choice != 'r' && choice != 'R')
    {
        load_on_loan(on_loan);
        print_on_loan(on_loan);

        std::cout << std::endl << ol_menu;
        choice = ol_menu.read_choice();
        switch(choice)
        {
            case '1':
                sort_by_id(on_loan);
                break;
            case '2':
                sort_by_name(on_loan);
                break;
            case '3':
                sort_by_author(on_loan);
                break;
            case '4':
                sort_by_date_of_borrowing(on_loan);
                break;
            case '5':
                sort_by_final_date(on_loan);
                break;
            case '6':
                std::reverse(on_loan.begin(), on_loan.end());
                break;
            case '7':
                return_book(library, on_loan);
                break;
            case 'R':
            case 'r':
                break; //breaking from this loop
            default:
                std::cout << "unknow choice" << std::endl;            
        }
        save_vec(on_loan, "ol_data.txt");
        save_vec(library, "lib_data.txt");
    }
}
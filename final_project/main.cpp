#include <iostream>

#include "menu_service.h"

#include "functions.h"

#include "Book.h"
#include "Library.h"
#include "On_Loan.h"

// 1. Projekt obiektowy:
// - klasy
// - konstruktory, destruktory
// - konstruktor kopiujacy -> zadeklarowany np w klasie Book
// - deklaracja przyjaciela -> I_Printable, Menu
// - dziedziczenie -> np. On_Loan dzidziczy z Library
// - polimorfizm -> np. print() we wszystkich klasach wywodzacych sie z I_Printable
// - klasa abstrakcyjna -> I_Printable, Menu
// - czysto wirtualne metody -> I_Printable

// 2. STL
// - szablony (np. vector , array) -> wszedzie
// - iteratory -> wypisywanie tabelki
// - algorytmy -> sortowanie tableki

// 3. C++
// - zakresowa petla for -> np. funkcja save_vec()
// - wlasny szablon klasy (lub funkcji) - niekonieczne 
// - przeciazanie operatorów -> I_printable
// - wyjatki -> wszedzie gdzie cos wprowadza uzytkownik
// - plik .h z deklaracja i .cpp z definicja metod - linke

int main() 
{
    std::vector<Book*> library;
    std::vector<Book*> on_loan;

    load_library(library);
    load_on_loan(on_loan);


    menu_f(library, on_loan);


    save_vec(library, "lib_data.txt");
    save_vec(on_loan, "ol_data.txt");

    delete_vec(library);
    delete_vec(on_loan);
    
    return 0;
}


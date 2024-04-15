#ifndef _PRINT_DATE_H_
#define _PRINT_DATE_H_

#include <vector>
#include <algorithm>

#include "functions.h"

#include "Main_Menu.h"
#include "Lib_Menu.h"
#include "OL_Menu.h"


#include "Book.h"
#include "Library.h"
#include "On_Loan.h"


void menu_f(std::vector<Book*> &library, std::vector<Book*> &on_loan);

void lib_menu_f(const Lib_Menu &lib_menu, std::vector<Book*> &library, std::vector<Book*> &on_loan);

void ol_menu_f(const OL_Menu &ol_menu, std::vector<Book*> &library, std::vector<Book*> &on_loan);

#endif // _PRINT_DATE_H_
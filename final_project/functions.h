#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

#include<algorithm>

#include "Book.h"
#include "Library.h"
#include "On_Loan.h"

using namespace std;

void reset_table_width();

void delete_vec(std::vector<Book*> &vec);

void load_library(std::vector<Book*> &library, std::string file_name = "lib_data.txt");

void save_vec(std::vector<Book*> &vec, std::string file_name);

void load_on_loan(std::vector<Book*> &on_loan, std::string file_name = "ol_data.txt");

int search_library(std::vector<Book*> &vec, int chosen_id);

int search_on_loan(std::vector<Book*> &vec, int chosen_id);

void lend_book(std::vector<Book*> &library, std::vector<Book*> &on_loan);

void delete_from_vec(std::vector<Book*> &vec, int pos);

void return_book(std::vector<Book*> &library, std::vector<Book*> &on_loan);

void add_to_library(std::vector<Book*> &library);

void remove_from_library(std::vector<Book*> &library);

int how_many_obj(std::string file_name, int size_of_obj); //size_of_obj -> how many args in obj

void print_library(const std::vector<Book*> &lib, bool show_unavailable);

void print_on_loan(const std::vector<Book*> &ol);


//comparing
bool cmp_id(Book* a, Book* b);

bool cmp_book_name(Book* a, Book* b);

bool cmp_book_author(Book* a, Book* b);

bool cmp_borrowers_id(Book* a, Book* b);

bool cmp_date_of_borrowing(Book* a, Book* b);

bool cmp_date_final_date(Book* a, Book* b);


//sorting
void sort_by_id(std::vector<Book*> &vec);

void sort_by_name(std::vector<Book*> &vec);

void sort_by_author(std::vector<Book*> &vec);

void sort_by_borrowers_id(std::vector<Book*> &vec);

void sort_by_date_of_borrowing(std::vector<Book*> &vec);

void sort_by_final_date(std::vector<Book*> &vec);

#endif // _FUNCTIONS_H
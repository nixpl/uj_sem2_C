#include "functions.h"

void reset_table_width(Book* a)
{
    a->table_colums_width.clear();
    a->table_colums_width = {sizeof("ID")-1,
                             sizeof("Book")-1,
                             sizeof("Author")-1,
                             sizeof("Available")-1,
                             sizeof("Borrower's id")-1,
                             sizeof("dd.mm.yyyy")-1,
                             sizeof("dd.mm.yyyy")-1};
}

void delete_vec(std::vector<Book*> &vec)
{
    for(auto &v: vec)
        delete v;
    vec.clear();
}

void load_library(std::vector<Book*> &library, std::string file_name)
{
    delete_vec(library);

    std::ifstream in_file {file_name};
    if(!in_file)
    {
        std::cout << "Could not find: " << file_name << std::endl;
        exit(1);
    }
    std::string id;
    std::string book_name;
    std::string author;
    std::string available;
    int available_int;

    int line {0};
    std::string buff;
    while(std::getline(in_file, buff))
    {
        switch(line % 4)
        {
        case 0:
            id = buff;
            break;
        case 1:
            book_name = buff;
            break;
        case 2:
            author = buff;
            break;
        case 3:
            available = buff;
            available_int = std::stoi(available);

            library.push_back(new Library {std::stoi(id), book_name, author, static_cast<bool>(available_int)});
            break;
        }
        line++;
    }
    in_file.close();
}

void save_vec(std::vector<Book*> &vec, std::string file_name)
{
    std::ofstream out_file {file_name};
    if(!out_file)
    {
        std::cout << "Could not find: " << file_name << std::endl;
        exit(1);
    }
    if(!vec.empty())
        reset_table_width(vec.at(0));

    for(auto &v: vec)
    {
        std::vector<std::string> data;
        v->get_data(data);
        for(auto &d: data)
            out_file << d << std::endl;
    }
    out_file.close();
}

void load_on_loan(std::vector<Book*> &on_loan, std::string file_name)
{
    delete_vec(on_loan);

    std::ifstream in_file {file_name};
    if(!in_file)
    {
        std::cout << "Could not find: " << file_name << std::endl;
        exit(1);
    }
    std::string id;
    std::string book_name;
    std::string author;
    std::string available;
    int available_int;
    std::string borrowers_id;
    int borrowers_id_int;
    std::string date_of_borrowing;
    int how_long_in_days;
    std::string final_date;

    int line {0};
    std::string buff;
    while(std::getline(in_file, buff))
    {
        switch(line % 8)
        {
        case 0:
            id = buff;
            break;
        case 1:
            book_name = buff;
            break;
        case 2:
            author = buff;
            break;
        case 3:
            available = buff;
            available_int = std::stoi(available);
            break;
        case 4:
            borrowers_id = buff;
            borrowers_id_int = std::stoi(borrowers_id);
            break;
        case 5:
            date_of_borrowing = buff;
            break;
        case 6:
            how_long_in_days = std::stoi(borrowers_id);
            break;
        case 7:
            final_date = buff;

            on_loan.push_back(new On_Loan {std::stoi(id), 
                                           book_name, 
                                           author, 
                                           static_cast<bool>(available_int), 
                                           static_cast<unsigned int>(borrowers_id_int), 
                                           date_of_borrowing, 
                                           static_cast<unsigned int>(how_long_in_days), 
                                           final_date});
            break;
        }
        line++;
    }
    in_file.close();
}

int search_library(std::vector<Book*> &vec, int chosen_id)
{
    for(size_t i {0}; i < vec.size(); ++i)
    {
        Library* ptr = dynamic_cast<Library*>(vec.at(i));
        if(ptr->get_id() == chosen_id)
           return i;
    }
    return -1;
}

int search_on_loan(std::vector<Book*> &vec, int chosen_id)
{
    for(size_t i {0}; i < vec.size(); ++i)
    {
        On_Loan* ptr = dynamic_cast<On_Loan*>(vec.at(i));
        if(ptr->get_id() == chosen_id)
           return i;
    }
    return -1;
}

void lend_book(std::vector<Book*> &library, std::vector<Book*> &on_loan)
{
    int chosen_id;
    std::cout << "Enter book id: ";
    
    try
    {
        if(!(std::cin >> chosen_id))
            throw std::runtime_error("Wrong number input");

        int pos {search_library(library, chosen_id)};

        if(pos == -1)
            std::cout << "There is no book with such id here" << std::endl;
        else
        {
            Library* ptr = dynamic_cast<Library*>(library.at(pos));
            if (!(ptr->get_available()))
                std::cout << "This book is already taken" << std::endl;
            else
            {
                unsigned int borrowers_id;
                std::cout << "Enter borrower's id: ";                
                if(!(std::cin >> borrowers_id))
                    throw std::runtime_error("Wrong number input");

                unsigned int days;
                std::cout << "For how long (in days): ";
                if(!(std::cin >> days))
                    throw std::runtime_error("Wrong number input");                
                
                ptr->set_available(false);

                on_loan.push_back(new On_Loan {*ptr, days, borrowers_id});

                std::cout << "borrowed!" << std::endl;
            }
        }
    }
    catch(const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void delete_from_vec(std::vector<Book*> &vec, int pos)
{
    delete vec.at(pos);

    for(size_t i {static_cast<size_t>(pos)}; i < (vec.size()-1); i++)
        vec.at(i)=vec.at(i+1);
    vec.pop_back();
}

void return_book(std::vector<Book*> &library, std::vector<Book*> &on_loan)
{
    try
    {
        int chosen_id;
        std::cout << "Enter book id: ";
        if(!(std::cin >> chosen_id))
            throw std::runtime_error("Wrong number input");

        int ol_pos {search_on_loan(on_loan, chosen_id)};

        if(ol_pos == -1)
            std::cout << "There is no book with such id here" << std::endl;
        else
        {
            On_Loan* ol_ptr = dynamic_cast<On_Loan*>(on_loan.at(ol_pos));

            unsigned int borrowers_id;
            std::cout << "Enter borrower's id: ";
            if(!(std::cin >> borrowers_id))
                throw std::runtime_error("Wrong number input");

            if (ol_ptr->get_borrowers_id() != borrowers_id)
                std::cout << "Wrong borrower's id" << std::endl;
            else
            {
                delete_from_vec(on_loan, ol_pos);
                Library* lib_ptr = dynamic_cast<Library*>(library.at(search_library(library, chosen_id)));
                lib_ptr->set_available(true);
                std::cout << "returned!" << std::endl;
            }
        }
    }
    catch(const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void add_to_library(std::vector<Book*> &library)
{
    library.push_back(new Library {});
}

void remove_from_library(std::vector<Book*> &library)
{
    try
    {
        int chosen_id;
        std::cout << "Enter book id: ";
        if(!(std::cin >> chosen_id))
            throw std::runtime_error("Wrong number input");

        int pos {search_library(library, chosen_id)};

        if(pos == -1)
            std::cout << "There is no book with such id here" << std::endl;
        else
        {
            Library* ptr = dynamic_cast<Library*>(library.at(pos));
            if(!(ptr->get_available()))
                std::cout << "This book cannot be removed. Wait for the return of the book" << std::endl;
            else
            {
                delete_from_vec(library, pos);
                std::cout << "removed!" << std::endl;
            }
            
        }
    }
    catch(const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }   

}

int how_many_obj(std::string file_name, int size_of_obj) //size_of_obj -> how many args in obj
{
    std::ifstream in_file {file_name};
    if(!in_file)
    {
        std::cout << "Could not find: " << file_name << std::endl;
        exit(1);
    }
    int counter {0};
    std::string buff;
    while(std::getline(in_file, buff))
        counter++;
    
    in_file.close();
    return counter/size_of_obj;
}

void print_library(const std::vector<Book*> &lib, bool show_unavailable)
{
    if(lib.empty())
        std::cout << "The Library is empty" << std::endl;
    else
    {
        std::vector<size_t> colums_width = lib.at(0)->table_colums_width;
        std::cout << std::endl;
        std::cout << "--LIBRARY-TABLE--" << std::endl;
        std::cout << std::setw(colums_width.at(0) + 3 +
                               colums_width.at(1) + 3 +
                               colums_width.at(2) + 3 +
                               colums_width.at(3)       ) << std::setfill('=') << "" << std::setfill(' ') << std::endl;
        std::cout << std::setw(colums_width.at(0)) << std::left << "ID" << " | "
                  << std::setw(colums_width.at(1)) << std::left << "Book" << " | " 
                  << std::setw(colums_width.at(2)) << std::left << "Author" << " | "
                  << std::setw(colums_width.at(3)) << std::left << "Available" << std::endl;
        std::cout << std::setw(colums_width.at(0) + 3 +
                               colums_width.at(1) + 3 +
                               colums_width.at(2) + 3 +
                               colums_width.at(3)       ) << std::setfill('=') << "" << std::setfill(' ') << std::endl;

        if(show_unavailable == true)
        {
            for(auto it = lib.begin(); it != lib.end(); ++it)
                std::cout << **it << std::endl;
        }
        else
        {
            for(auto it = lib.begin(); it != lib.end(); ++it)
            {
                Library* ptr = dynamic_cast<Library*>(*it);
                if(ptr->get_available())
                    std::cout << *ptr << std::endl;            
            }
        }
        std::cout << std::setw(colums_width.at(0) + 3 +
                               colums_width.at(1) + 3 +
                               colums_width.at(2) + 3 +
                               colums_width.at(3)       ) << std::setfill('=') << "" << std::setfill(' ') << std::endl; 
    }
        
}

void print_on_loan(const std::vector<Book*> &ol)
{
    if(ol.empty())
        std::cout << "There are no borrowed books" << std::endl;
    else
    {
        std::vector<size_t> colums_width = ol.at(0)->table_colums_width;
        std::cout << std::endl;
        std::cout << "--ON-LOAN-TABLE--" << std::endl;
        std::cout << std::setw(colums_width.at(0) + 3 +
                               colums_width.at(1) + 3 +
                               colums_width.at(2) + 3 +
                               colums_width.at(3) + 3 +
                               colums_width.at(4) + 3 +
                               colums_width.at(5) + 3 +
                               colums_width.at(6)       ) << std::setfill('=') << "" << std::setfill(' ') << std::endl;
        std::cout << std::setw(colums_width.at(0)) << std::left << "ID" << " | "
                  << std::setw(colums_width.at(1)) << std::left << "Book" << " | " 
                  << std::setw(colums_width.at(2)) << std::left << "Author" << " | "
                  << std::setw(colums_width.at(3)) << std::left << "Available" << " | " 
                  << std::setw(colums_width.at(4)) << std::left << "Borrower's ID" << " | " 
                  << std::setw(colums_width.at(5)+ 3 + colums_width.at(6)) << std::left << "Book loan period" << std::endl;
        std::cout << std::setw(colums_width.at(0) + 3 +
                               colums_width.at(1) + 3 +
                               colums_width.at(2) + 3 +
                               colums_width.at(3) + 3 +
                               colums_width.at(4) + 3 +
                               colums_width.at(5) + 3 +
                               colums_width.at(6)       ) << std::setfill('=') << "" << std::setfill(' ') << std::endl;

        for(auto it = ol.begin(); it != ol.end(); ++it)
            std::cout << **it << std::endl; 

        std::cout << std::setw(colums_width.at(0) + 3 +
                               colums_width.at(1) + 3 +
                               colums_width.at(2) + 3 +
                               colums_width.at(3) + 3 +
                               colums_width.at(4) + 3 +
                               colums_width.at(5) + 3 +
                               colums_width.at(6)       ) << std::setfill('=') << "" << std::setfill(' ') << std::endl;
    }    
}


//compering
bool cmp_id(Book* a, Book* b)
{
    Library* a_ptr = dynamic_cast<Library*>(a);
    Library* b_ptr = dynamic_cast<Library*>(b);

    if(a_ptr->get_id() < b_ptr->get_id())
        return true;
    else
        return false; 
}

bool cmp_book_name(Book* a, Book* b)
{
    if(a->get_name() < b->get_name())
        return true;
    else
        return false;
}

bool cmp_book_author(Book* a, Book* b)
{
    if(a->get_author() < b->get_author())
        return true;
    else
        return false;  
}

bool cmp_borrowers_id(Book* a, Book* b)
{
    On_Loan* a_ptr = dynamic_cast<On_Loan*>(a);
    On_Loan* b_ptr = dynamic_cast<On_Loan*>(b);

    if(a_ptr->get_borrowers_id() < b_ptr->get_borrowers_id())
        return true;
    else
        return false;
}

bool cmp_date_of_borrowing(Book* a, Book* b)
{
    On_Loan* a_ptr = dynamic_cast<On_Loan*>(a);
    On_Loan* b_ptr = dynamic_cast<On_Loan*>(b);

    std::string a_date {a_ptr->get_date_of_borrowing()};
    std::string b_date {b_ptr->get_date_of_borrowing()};

    //dd.mm.yyyy
    std::string a_day {a_date.substr(0, 2)}; //1st -> start index, second -> size of new string
    std::string a_month {a_date.substr(3, 2)};
    std::string a_year {a_date.substr(6, 4)};

    std::string b_day {b_date.substr(0, 2)}; 
    std::string b_month {b_date.substr(3, 2)};
    std::string b_year {b_date.substr(6, 4)};

    if(a_year < b_year)
        return true;
    else if(a_year > b_year)
        return false;
        
    if(a_month < b_month)
        return true;
    else if(a_month > b_month)
        return false;

    if(a_day < b_day)
        return true;
    else
        return false;
}

bool cmp_date_final_date(Book* a, Book* b)
{
    On_Loan* a_ptr = dynamic_cast<On_Loan*>(a);
    On_Loan* b_ptr = dynamic_cast<On_Loan*>(b);

    std::string a_date {a_ptr->get_final_date()};
    std::string b_date {b_ptr->get_final_date()};

    //dd.mm.yyyy
    std::string a_day {a_date.substr(0, 2)}; //1st -> start index, second -> size of new string
    std::string a_month {a_date.substr(3, 2)};
    std::string a_year {a_date.substr(6, 4)};

    std::string b_day {b_date.substr(0, 2)}; 
    std::string b_month {b_date.substr(3, 2)};
    std::string b_year {b_date.substr(6, 4)};

    if(a_year < b_year)
        return true;
    else if(a_year > b_year)
        return false;
        
    if(a_month < b_month)
        return true;
    else if(a_month > b_month)
        return false;

    if(a_day < b_day)
        return true;
    else
        return false;
}


//sorting
void sort_by_id(std::vector<Book*> &vec)
{
    std::sort(vec.begin(), vec.end(), cmp_id);    
}

void sort_by_name(std::vector<Book*> &vec)
{
    std::sort(vec.begin(), vec.end(), cmp_book_name);
}

void sort_by_author(std::vector<Book*> &vec)
{
    std::sort(vec.begin(), vec.end(), cmp_book_author);
}

void sort_by_borrowers_id(std::vector<Book*> &vec)
{
    std::sort(vec.begin(), vec.end(), cmp_borrowers_id);
}

void sort_by_date_of_borrowing(std::vector<Book*> &vec)
{
    std::sort(vec.begin(), vec.end(), cmp_date_of_borrowing);
}

void sort_by_final_date(std::vector<Book*> &vec)
{
    std::sort(vec.begin(), vec.end(), cmp_date_final_date);
}

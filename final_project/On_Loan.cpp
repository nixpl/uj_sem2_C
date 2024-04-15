#include "On_Loan.h"

//constructor:
On_Loan::On_Loan(int id,
                std::string name, 
                std::string author, 
                bool available,
                unsigned int borrowers_id, 
                std::string date_of_borrowing,
                unsigned int how_long_in_days,
                std::string final_date)
:Library(id, name, author, available),
    date_of_borrowing{date_of_borrowing}, // date_of_borrowing{(std::chrono::system_clock::now())}
    how_long_in_days{how_long_in_days},  
    final_date{final_date}, // final_date{date_of_borrowing + std::chrono::hours(24 * how_long_in_days)}
    borrowers_id{borrowers_id} 
{
    std::string buff {std::to_string(borrowers_id)};

    if(buff.size() > table_colums_width.at(4))
        table_colums_width.at(4) = buff.size();  
}

On_Loan::On_Loan(Library &lib, unsigned int how_long_in_days, unsigned int borrowers_id)
:On_Loan(lib.get_id(), 
         lib.get_name(), 
         lib.get_author(), 
         lib.get_available(),
         borrowers_id,
         date_to_string(0),
         how_long_in_days,
         date_to_string(how_long_in_days)){}

//Copy constructor:
On_Loan::On_Loan(const On_Loan &sorce)
:Library(sorce),
    date_of_borrowing{sorce.date_of_borrowing},
    how_long_in_days{sorce.how_long_in_days},
    final_date{sorce.final_date},
    borrowers_id{sorce.borrowers_id} {}

unsigned int On_Loan::get_borrowers_id() const
{
    return borrowers_id;
}
std::string On_Loan::get_date_of_borrowing() const
{
    return date_of_borrowing;
}
std::string On_Loan::get_final_date() const
{
    return final_date;
}

void On_Loan::get_data(std::vector<std::string> &data) const
{
    Library::get_data(data);
    data.push_back(std::to_string(borrowers_id));
    data.push_back(date_of_borrowing);
    data.push_back(std::to_string(how_long_in_days));
    data.push_back(final_date);
}

void On_Loan::print(std::ostream &os) const
{
    Library::print(os); 

    std::cout << " | " << std::setw(table_colums_width.at(4)) << std::left << borrowers_id;

    std::cout << " | " << std::setw(table_colums_width.at(5)) << std::left << date_of_borrowing;

    std::cout << " - " << std::setw(table_colums_width.at(6)) << std::left  << final_date;
}

On_Loan::~On_Loan() {}

#ifndef _ON_LOAN_H_
#define _ON_LOAN_H_
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "print_date.h"
#include "Library.h"

class On_Loan: public Library 
{ 
    private:
        static constexpr unsigned int def_borrowers_id = 0;
        static constexpr unsigned int def_how_long_in_days = 14;

    protected:
        //std::chrono::system_clock::time_point date_of_borrowing;
        std::string date_of_borrowing;
        unsigned int how_long_in_days;
        //std::chrono::system_clock::time_point final_date;
        std::string final_date;
        unsigned int borrowers_id;
        
    public:
        //constructor:
        On_Loan(int id = 0,
                std::string name = def_name, 
                std::string author = def_author, 
                bool available = false,
                unsigned int borrowers_id = def_borrowers_id, 
                std::string date_of_borrowing = "00.00.0000", 
                unsigned int how_long_in_days = def_how_long_in_days,
                std::string final_date = "00.00.0000");

        On_Loan(Library &lib, unsigned int how_long_in_days, unsigned int borrowers_id);

        //Copy constructor:
        On_Loan(const On_Loan &sorce);

        virtual unsigned int get_borrowers_id() const;
        virtual std::string get_date_of_borrowing() const;
        virtual std::string get_final_date() const;

        virtual void get_data(std::vector<std::string> &data) const override; 

        //virtual bool give_back();

        virtual void print(std::ostream &os) const override;

        //destructor
        virtual ~On_Loan();
};

#endif // _ON_LOAN_H_
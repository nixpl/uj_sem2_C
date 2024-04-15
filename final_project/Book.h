#ifndef _BOOK_H_
#define _BOOK_H_
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <queue>
#include "I_Printable.h"

class Book: public I_Printable 
{   
    
    private:  
        
    protected:

        friend bool cmp_name(const Book &a, const Book &b);
        friend bool cmp_author(const Book &a, const Book &b);

        static constexpr const char *def_name = "Unnamed Book";
        static constexpr const char *def_author = "Unknow Author";

        std::string name;
        std::string author;

    public:
        //file constructor:
        Book(std::ifstream &in_file);
        //constructor:
        Book(std::string name = def_name, std::string author = def_author);
        //Copy constructor:
        Book(const Book &sorce);

        virtual std::string get_name() const;
        virtual std::string get_author() const;

        virtual void get_data(std::vector<std::string> &data) const override; 

        virtual void print(std::ostream &os) const override;

        //destructor
        virtual ~Book();
};
#endif //_BOOK_H_
#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <queue>
#include "Book.h"

class Library: public Book 
{
    private:
        static int id_counter;
        friend int id_counter_load(std::queue<int> &blank_id);

    protected:

        friend bool cmp_available(const Library &a, const Library &b);

        int id;
        bool available;
        
    public:
        //constructor:
        Library();
        
        Library(int id, std::string name, std::string author, bool available = true);

        //Copy constructor:
        Library(const Library &sorce);

        virtual int get_id() const;
        virtual bool get_available() const;

        virtual void get_data(std::vector<std::string> &data) const override;

        void set_available(bool statement);
        //virtual bool lend_book(); // !!musi zmianiać available na false!!

        virtual void print(std::ostream &os) const override; 

        //destructor
        virtual ~Library();
};

#endif // _LIBRARY_H_
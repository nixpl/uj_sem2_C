#ifndef _I_PRINTABLE_H_
#define _I_PRINTABLE_H_

#include <iostream>
#include <vector>

class I_Printable
{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
    
    public:
        static std::vector<size_t> table_colums_width;

        virtual void get_data(std::vector<std::string> &data) const = 0;

        virtual void print(std::ostream &os) const = 0;
        virtual ~I_Printable() = default;
};

#endif
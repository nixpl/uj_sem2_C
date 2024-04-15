#include "I_Printable.h"

std::vector<size_t> I_Printable::table_colums_width {sizeof("ID")-1,
                                                     sizeof("Book")-1,
                                                     sizeof("Author")-1,
                                                     sizeof("Available")-1,
                                                     sizeof("Borrower's id")-1,
                                                     sizeof("dd.mm.yyyy")-1,
                                                     sizeof("dd.mm.yyyy")-1};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) 
{
    obj.print(os);
    return os;
}
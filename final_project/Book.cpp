#include "Book.h"



bool cmp_name(const Book &a, const Book &b)
{
    return a.name < b.name;
}

bool cmp_author(const Book &a, const Book &b)
{
    return a.author < b.author;
}


//file constructor:
Book::Book(std::ifstream &in_file)
{
    std::getline(in_file, name);
    std::getline(in_file, author);

    if(name.size() > table_colums_width.at(1))
        table_colums_width.at(1) = name.size();
    
    if(author.size() > table_colums_width.at(2))
        table_colums_width.at(2) = author.size();
}

//constructor:
Book::Book(std::string name, std::string author)
:name{name}, author{author} 
{
    if(name.size() > table_colums_width.at(1))
        table_colums_width.at(1) = name.size();
    
    if(author.size() > table_colums_width.at(2))
        table_colums_width.at(2) = author.size();
}

//Copy constructor:
Book::Book(const Book &sorce)
:name{sorce.name}, author{sorce.author} {}

std::string Book::get_name() const
{
    return name;
}
std::string Book::get_author() const
{
    return author;
}

void Book::get_data(std::vector<std::string> &data) const
{
    data.push_back(name);
    data.push_back(author);
}

void Book::print(std::ostream &os) const
{
    std::cout << std::setw(table_colums_width.at(1)) << std::left << name << " | " 
              << std::setw(table_colums_width.at(2)) << std::left << author;
}

Book::~Book()
{
 
}
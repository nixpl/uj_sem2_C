#include "Library.h"

int id_counter_load()
{
    std::ifstream in_file {"id_data.txt"};
    if(!in_file)
    {
        std::cout << "Could not find: " << "id_data.txt" << std::endl;
        exit(1);
    }
    int id_counter_buff;
    in_file >> id_counter_buff;

    in_file.close();
    return id_counter_buff;
}

int Library::id_counter {id_counter_load()};

bool cmp_available(const Library &a, const Library &b)
{
    if(a.available == true && b.available == false)
        return true;
    else
        return false;
}   

//constructor:
Library::Library()
{
    id = ++id_counter;

    std::cin.ignore();

    std::cout << "Enter book name: ";
    std::getline(std::cin, name);

    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    available = true;

    if(name.size() > table_colums_width.at(1))
        table_colums_width.at(1) = name.size();
    
    if(author.size() > table_colums_width.at(2))
        table_colums_width.at(2) = author.size();

    std::string buff{std::to_string(id_counter)};
    if(buff.size() > table_colums_width.at(0))
        table_colums_width.at(0) = buff.size();
}

Library::Library(int id, std::string name, std::string author, bool available)
:Book(name, author), id{id}, available{available} {}


//Copy constructor:
Library::Library(const Library &sorce)
:Book(sorce), id{id}, available{sorce.available} {}


int Library::get_id() const
{
    return id;
}
bool Library::get_available() const
{
    return available;
}

void Library::get_data(std::vector<std::string> &data) const
{
    data.push_back(std::to_string(id));
    Book::get_data(data);
    data.push_back(std::to_string(available));
}

void Library::set_available(bool statement)
{
    available = statement;
}

void Library::print(std::ostream &os) const
{
    std::cout << std::setw(table_colums_width.at(0)) << std::left << id << " | ";

    Book::print(os);

    std::string statement {available ? "Yes" : "No"}; 
    std::cout << " | " << std::setw(table_colums_width.at(3)) << std::left << statement;
}

Library::~Library() 
{
    std::ofstream out_file {"id_data.txt"};
    if(!out_file)
    {
        std::cout << "Could not find: " << "id_data.txt" << std::endl;
        exit(1);
    }
    out_file << id_counter << std::endl;
    out_file.close();   
}
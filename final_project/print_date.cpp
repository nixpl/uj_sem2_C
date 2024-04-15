#include "print_date.h"


std::string date_to_string(const unsigned int days)
{
    std::time_t now = std::time(nullptr);
    std::tm* time = std::localtime(&now);

    time->tm_mday+=days;
    std::mktime(time);

    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", time);
    std::string date_string {buffer};
    return date_string;
}

#ifndef DATABASE
#define DATABASE

#include <vector>
#include <fstream>

namespace Db
{
    typedef struct
    {
        char brand[50];
        char model[50];
        float display_size;
        char cpu_name[50];
    } Phone;

    typedef std::vector<Phone> PhoneDB;

    std::vector<Phone> load_db();

    void write_db(const std::vector<Phone> &db_list);
} // namespace Db

#endif
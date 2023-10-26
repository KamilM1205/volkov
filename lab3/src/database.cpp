#include "include/database.hpp"

namespace Db
{
    PhoneDB load_db()
    {
        std::vector<Phone> db_list;
        std::fstream db_file;
        typename std::vector<Phone>::size_type vec_size = 0;

        db_file.open("database.bin", std::ios::binary | std::ios::in);
        if (db_file.good())
        {
            db_file.read((char *)&vec_size, sizeof(vec_size));
            db_list.resize(vec_size);
            db_file.read((char *)&db_list[0], db_list.size() * sizeof(Phone));
        }
        db_file.close();

        return db_list;
    }

    void write_db(const PhoneDB &db_list)
    {
        std::fstream db_file;
        typename std::vector<Phone>::size_type vec_size = db_list.size();
        db_file.open("database.bin", std::ios::binary | std::ios::out | std::ios::trunc);
        db_file.write((char *)&vec_size, sizeof(vec_size));
        db_file.write((char *)&db_list[0], db_list.size() * sizeof(Phone));
        db_file.close();
    }
} // namespace Db

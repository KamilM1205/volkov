#include "include/app.hpp"

namespace APP
{
    void display_all(const Db::PhoneDB &db)
    {
        if (db.empty())
        {
            printf("Nothing to show\n");
            return;
        }

        for (const auto &i : db)
        {
            printf(FORMATTED_DB, i.brand, i.model, i.display_type,
                   i.display_size, i.display_rate, i.wheight, i.cpu_name,
                   i.core_count, i.ram_size, i.rom_size);
        }
        return;
    }

    void insert_record(Db::PhoneDB &db)
    {
        Db::Phone buff;
        std::string temp;
        // Brand
        printf("Brand: ");
        std::cin.getline(buff.brand, 50);

        // Model
        printf("Model: ");
        std::cin.getline(buff.model, 50);

        // Display size
        printf("Display size: ");
        std::getline(std::cin, temp);
        buff.display_size = std::stof(temp);

        // CPU name
        printf("CPU name: ");
        std::cin.getline(buff.cpu_name, 50);

        Repository::insert(db, buff);
    }

    void search_records(const Db::PhoneDB &db)
    {
        std::string temp;
        Db::PhoneDB found;

        printf(SEARCH_BY);
        printf(">>");
        std::getline(std::cin, temp);
        found.clear();
        printf("Value to search>>");

        switch (std::stoi(temp))
        {
        case 1:
            std::getline(std::cin, temp);
            for (const auto &i : db_list)
            {
                if (i.brand == temp)
                {
                    found.push_back(i);
                }
            }
            break;
        case 2:
            std::getline(std::cin, temp);
            repository
            break;
        case 3:
            std::getline(std::cin, temp);
            for (const auto &i : db_list)
            {
                if (i.display_size == std::stof(temp))
                {
                    found.push_back(i);
                }
            }
            break;
        case 4:
            std::getline(std::cin, temp);
            for (const auto &i : db_list)
            {
                if (i.cpu_name == temp)
                {
                    found.push_back(i);
                }
            }
            break;
        default:
            printf("Command: %s not found.", temp.c_str());
        }

        if (!found.empty())
            for (const auto &i : found)
                printf(FORMATTED_DB, i.brand, i.model, i.display_type,
                       i.display_size, i.display_rate, i.wheight, i.cpu_name,
                       i.core_count, i.ram_size, i.rom_size);
        else
            printf("It seems nothing was found...\n");
    }
} // namespace APP

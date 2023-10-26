#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

// Messages

#define MENU "Menu:\n\
\t1. Show record. \n\
\t2. Write record. \n\
\t3. Search. \n\
\t4. Save and exit. \n\
"

#define FORMATTED_DB "Phone:\n\
\tBrand: %s\n\
\tModel: %s\n\
\tDisplay type: %s\n\
\tDisplay size: %f\n\
\tDisplay rate: %d\n\
\tWheight: %d\n\
\tCPU name: %s\n\
\tCPU cores: %d\n\
\tRAM: %d\n\
\tROM: %d\n\
"

#define SEARCH_BY "1. By brand\n\
2. By model\n\
3. By display type\n\
4. By display size\n\
5. By display rate\n\
6. By wheight\n\
7. By CPU name\n\
8. By CPU cores\n\
9. By RAM\n\
10. By ROM\n"

// Phones db

typedef struct
{
    char brand[50];
    char model[50];
    char display_type[12];
    float display_size;
    int display_rate;
    int wheight;
    char cpu_name[50];
    int core_count;
    int ram_size;
    int rom_size;
} Phone;

int main()
{
    Phone* buff;
    std::vector<Phone*> db_list;
    std::string cmd;
    std::string temp;
    std::vector<Phone*> found;
    bool isRunning = true;
    std::fstream db_file;
    typename std::vector<Phone*>::size_type vec_size = 0;

    db_file.open("database.bin", std::ios::binary | std::ios::in);
    if (db_file.good()) {
        db_file.read((char*)&vec_size, sizeof(vec_size));
        db_list.resize(vec_size);
        for (size_t i = 0; i < vec_size; i++) {
            Phone phone{};
            db_file.read((char*)&phone, sizeof(Phone));
            db_list[i] = new Phone(phone);
        }
    }
    db_file.close();

    while (isRunning)
    {
        printf(MENU);
        printf(">>");
        std::getline(std::cin, cmd);
        int selection = atoi(cmd.c_str());

        switch (selection)
        {
        case 1:
            if (db_list.empty()) {
                printf("Nothing to show\n");
                break;
            }

            for (const auto& i : db_list)
            {
                printf(FORMATTED_DB, i->brand, i->model, i->display_type,
                       i->display_size, i->display_rate, i->wheight, i->cpu_name,
                       i->core_count, i->ram_size, i->rom_size);
            }
            break;
        case 2:
            buff = new Phone;
            // Brand
            printf("Brand: ");
            std::cin.getline(buff->brand, 50);

            // Model
            printf("Model: ");
            std::cin.getline(buff->model, 50);

            // Display type
            printf("Display type: ");
            std::cin.getline(buff->display_type, 12);

            // Display size
            printf("Display size: ");
            std::getline(std::cin, temp);
            buff->display_size = std::stof(temp);

            // Display rate
            printf("Display rate: ");
            std::getline(std::cin, temp);
            buff->display_rate = std::stoi(temp);

            // Wheight
            printf("Wheight: ");
            std::getline(std::cin, temp);
            buff->wheight = std::stoi(temp);

            // CPU name
            printf("CPU name: ");
            std::cin.getline(buff->cpu_name, 50);

            // Core count
            printf("Core count: ");
            std::getline(std::cin, temp);
            buff->core_count = std::stoi(temp);

            // RAM size
            printf("RAM: ");
            std::getline(std::cin, temp);
            buff->ram_size = std::stoi(temp);

            // ROM size
            printf("ROM: ");
            std::getline(std::cin, temp);
            buff->rom_size = std::stoi(temp);

            db_list.push_back(buff);
            break;
        case 3:
            printf(SEARCH_BY);
            printf(">>");
            std::getline(std::cin, temp);
            found.clear();
            printf("Value to search>>");

            switch (std::stoi(temp))
            {
            case 1:
                std::getline(std::cin, temp);
                for (const auto& i : db_list) {
                    if (i->brand == temp) {
                        found.push_back(i);
                    }
                }
                break;
            case 2:
                std::getline(std::cin, temp);
                for (const auto& i : db_list) {
                    if (i->model == temp) {
                        found.push_back(i);
                    }
                }
                break;
            case 3:
                std::getline(std::cin, temp);
                for (const auto& i : db_list) {
                    if (i->display_type == temp) {
                        found.push_back(i);
                    }
                }
                break;
            case 4:
                std::getline(std::cin, temp);
                for (const auto& i : db_list) {
                    if (i->display_size == std::stof(temp)) {
                        found.push_back(i);
                    }
                }
                break;
            case 5:
                std::getline(std::cin, temp);
                for (const auto& i : db_list) {
                    if (i->display_rate == std::stoi(temp)) {
                        found.push_back(i);
                    }
                }
                break;
            case 6:
                std::getline(std::cin, temp);
                for (const auto& i : db_list) {
                    if (i->wheight == std::stoi(temp)) {
                        found.push_back(i);
                    }
                }
                break;
            case 7:
                std::getline(std::cin, temp);
                for (const auto& i : db_list) {
                    if (i->cpu_name == temp) {
                        found.push_back(i);
                    }
                }
                break;
            case 8:
                std::getline(std::cin, temp);
                for (const auto& i : db_list) {
                    if (i->core_count == std::stoi(temp)) {
                        found.push_back(i);
                    }
                }
                break;
            case 9:
                std::getline(std::cin, temp);
                for (const auto& i : db_list) {
                    if (i->ram_size == std::stoi(temp)) {
                        found.push_back(i);
                    }
                }
                break;
            case 10:
                std::getline(std::cin, temp);
                for (const auto& i : db_list) {
                    if (i->rom_size == std::stoi(temp)) {
                        found.push_back(i);
                    }
                }
                break;
            
            default:
                printf("Command: %s not found.", temp.c_str());
            }

            if (!found.empty())
                for (const auto &i : found)
                    printf(FORMATTED_DB, i->brand, i->model, i->display_type,
                           i->display_size, i->display_rate, i->wheight, i->cpu_name,
                           i->core_count, i->ram_size, i->rom_size);
            else
                printf("It seems nothing was found...\n");
            break;
        case 4:
            isRunning = false;

            db_file.open("database.bin", std::ios::binary | std::ios::out | std::ios::trunc);
            vec_size = db_list.size();
            db_file.write((char*)&vec_size, sizeof(vec_size));
            for (const auto& d : db_list)
                db_file.write((char*)d, sizeof(Phone));
            db_file.close();

            for (auto& i : db_list)
                delete(i);

            break;
        default:
            printf("This selection not found.\n");
            continue;
        }
    }
}
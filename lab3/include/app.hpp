#ifndef APP
#define APP

#include "database.hpp"
#include "repository.hpp"

namespace App
{
    #define MENU "Menu:\n\
\t1. Show record. \n\
\t2. Write record. \n\
\t3. Search. \n\
\t4. Save and exit. \n\
"

#define FORMATTED_DB "Phone:\n\
\tBrand: %s\n\
\tModel: %s\n\
\tDisplay size: %f\n\
\tCPU name: %s\n\
"

#define SEARCH_BY "1. By brand\n\
2. By model\n\
3. By display size\n\
4. By CPU name\n"


void display_all(const Db::PhoneDB &db);

void insert_record(Db::PhoneDB &db);

void search_records(const Db::PhoneDB &db);

} // namespace App


#endif
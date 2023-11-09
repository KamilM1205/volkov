#ifndef REPOSITORY
#define REPOSITORY

#include "database.hpp"

namespace Repository {
enum class Error { NOT_FOUND, OK };

void insert(std::vector<Db::Phone> &db, Db::Phone data);

Error get(std::vector<Db::Phone> db, Db::Phone &data, size_t idx);

void search_by_brand(const Db::PhoneDB &db, Db::PhoneDB &res, std::string &v);

void search_by_model(const Db::PhoneDB &db, Db::PhoneDB &res, std::string &v);

void search_by_display_size(const Db::PhoneDB &db, Db::PhoneDB &res, int v);

void search_by_cpu(const Db::PhoneDB &db, Db::PhoneDB &res, std::string &v);
} // namespace Repository

#endif

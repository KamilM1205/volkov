#include "include/repository.hpp"

namespace Repository
{
    void insert(std::vector<Db::Phone> db, Db::Phone data) {
        db.push_back(data);
    }

    Error get(std::vector<Db::Phone> db, Db::Phone& data, size_t idx) {
        if (idx < db.size())
            data = db[idx];
        else
            return Error::NOT_FOUND;
        
        return Error::OK;
    }

    Error search_by_brand(const Db::PhoneDB& db, Db::PhoneDB& res, std::string& v) {
        for (const auto& i : db) {
            if (i.brand == v) {
                res.push_back(i);
            }
        }

        if (res.empty())
            return Error::NOT_FOUND;
        
        return Error::OK;
    }

    Error search_by_model(const Db::PhoneDB& db, Db::PhoneDB& res, std::string& v) {
        for (const auto& i : db) {
            if (i.model == v) {
                res.push_back(i);
            }
        }

        if (res.empty())
            return Error::NOT_FOUND;
        
        return Error::OK;
    }

    Error search_by_display_size(const Db::PhoneDB& db, Db::PhoneDB& res, int v) {
        for (const auto& i : db) {
            if (i.display_size == v) {
                res.push_back(i);
            }
        }

        if (res.empty())
            return Error::NOT_FOUND;
        
        return Error::OK;
    }

    Error search_by_cpu(const Db::PhoneDB& db, Db::PhoneDB& res, std::string& v) {
        for (const auto& i : db) {
            if (i.cpu_name == v) {
                res.push_back(i);
            }
        }

        if (res.empty())
            return Error::NOT_FOUND;
        
        return Error::OK;
    }
} // namespace Repository

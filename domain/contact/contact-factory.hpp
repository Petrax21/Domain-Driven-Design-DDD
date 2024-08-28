#ifndef CONTACT_FACTORY_HPP
#define CONTACT_FACTORY_HPP

#include <pqxx/pqxx>
#include "json/include/nlohmann/json.hpp"

using json = nlohmann::json;

namespace ContactFactory
{
    json generateGetContactList(pqxx::result res) {
        json jArray = json::array();
        for (auto row : res) {
            json jObject;
            jObject["ad"] = row[0].c_str();
            jObject["soyad"] = row[1].c_str();
            jObject["telefon"] = row[2].c_str();
            jArray.push_back(jObject);
        }
        return jArray.dump();
    }
}

#endif //CONTACT_FACTORY_HPP
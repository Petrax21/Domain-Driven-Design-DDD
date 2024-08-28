#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include "json/include/nlohmann/json.hpp"

#include "../domain/contact/contact-service.hpp"

using json = nlohmann::json;

namespace ApplicationService
{
    pqxx::connection* conn = nullptr;

    inline void connectToDatabase() {
        try {
            conn = new pqxx::connection("dbname=rehber user=mustafa password=sitil.2134 hostaddr=127.0.0.1 port=5432");
        } catch (const std::exception& e) {
            std::cerr << "Connection failed: " << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    inline void addContact(const std::string& req) {
        json j = json::parse(req);
        std::string ad = j["ad"];
        std::string soyad = j["soyad"];
        std::string telefon = j["telefon"];

        ContactService::addContact(ad, soyad, telefon);
    }

    inline void deleteContact(const std::string& req) {
        json j = json::parse(req);
        std::string ad = j["ad"];
        std::string soyad = j["soyad"];
        std::string telefon = j["telefon"];

        ContactService::deleteContactFromDatabase(ad, soyad, telefon);
    }

    inline std::string getContactList() {
        return ContactService::getContactList();
    }

    void cleanup() {
        delete conn;
    }
}

#endif //SERVICE_HPP
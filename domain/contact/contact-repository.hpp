#ifndef CONTACT_REPOSITORY_HPP
#define CONTACT_REPOSITORY_HPP

#include <pqxx/pqxx>
#include "contact-factory.hpp"

namespace ContactRepository
{
    pqxx::connection* conn = nullptr;

    inline std::string getContactsFromDatabase() {
        pqxx::work txn(*conn);
        pqxx::result res = txn.exec("SELECT first_name, last_name, phone FROM contacts");
        txn.commit();

        return ContactFactory::generateGetContactList(res);
    }

    inline void addContactToDatabase(const std::string& firstName, const std::string& lastName, const std::string& phone) {
        pqxx::work txn(*conn);
        txn.exec0("INSERT INTO contacts (first_name, last_name, phone) VALUES (" +
                  txn.quote(firstName) + ", " +
                  txn.quote(lastName) + ", " +
                  txn.quote(phone) + ")");
        txn.commit();
    }

    inline void deleteContactFromDatabase(const std::string& firstName, const std::string& lastName, const std::string& phone) {
        pqxx::work txn(*conn);
        txn.exec0("DELETE FROM contacts WHERE first_name = " +
                  txn.quote(firstName) + " AND " +
                  "last_name = " + txn.quote(lastName) + " AND " +
                  "phone = " + txn.quote(phone));
        txn.commit();
    }
}

#endif //CONTACT_REPOSITORY_HPP
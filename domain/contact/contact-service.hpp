#ifndef CONTACT_SERVICE_HPP
#define CONTACT_SERVICE_HPP

#include "contact-repository.hpp"

namespace ContactService
{
    void inline addContact(const std::string& firstName, const std::string& lastName, const std::string& phone) {
        ContactRepository::addContactToDatabase(firstName, lastName, phone);
    }
    std::string getContactList();
    void addContactToDatabase(const std::string& firstName, const std::string& lastName, const std::string& phone);
    void deleteContactFromDatabase(const std::string& firstName, const std::string& lastName, const std::string& phone);
};

#endif //CONTACT_SERVICE_HPP
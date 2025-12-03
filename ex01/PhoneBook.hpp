
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <ctime>
# include "Contact.hpp"

class PhoneBook
{
    private:
            Contact contacts[8];
            int contactCount;
            int oldestIndex;

            void displayContactTable() const;
            void displayContactDetails(int index) const;
            std::string truncateField(std::string field) const;
            void promptForContactInfo(Contact &contact);

    public:
            PhoneBook();
            void addContact();
            void searchContact() const;
};


#endif
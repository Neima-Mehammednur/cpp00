
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

std::string PhoneBook::truncateField(std::string field) const
{
    if(field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void PhoneBook::displayContactTable() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nick Name" << "|" << std::endl;

    std::cout << "----------|----------|----------|-----------" << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncateField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateField(contacts[i].getNickName()) << std::endl;
    }
}

void PhoneBook::displayContactDetails(int index) const
{
    std::cout << "\n---Contact Details---" << std::endl;
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nick Name: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number : " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::promptForContactInfo(Contact &contact)
{
    std::string input;

    //for first name
    std::cout << "Enter first Name: ";
    std::getline(std::cin, input);
    while(input.empty())
    {
        std::cout << "Field cannot be Empty! Please Enter first name: ";
        std::getline(std::cin, input);
    }
    contact.setFirstName(input);


    //for last name

    std::cout << "Enter Last name: ";
    std::getline(std::cin, input);
    while(input.empty())
    {
        std::cout << "Field cannot be Empty, Please enter Last Name: ";
        std::getline(std::cin, input);
    }
    contact.setLastName(input);

    //for nick name

    std::cout << "Enter Nick Name: ";
    std::getline(std::cin, input);
    while(input.empty())
    {
        std::cout << "Field cannot be Empty, Please Enter Nick Name: ";
        std::getline(std::cin, input);
    }
    contact.setNickName(input);

    //for phone number

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    while(input.empty())
    {
        std::cout << "Field cannot be empty, Please Enter Phone Number: ";
        std::getline(std::cin, input);
    }
    contact.setPhoneNumber(input);

    // darkest secret
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    while(input.empty())
    {
        std::cout << "Field cannot be empty, Please Enter Darkest Secret: ";
        std::getline(std::cin, input);
    }
    contact.setDarkestSecret(input);

}



void PhoneBook::addContact()
{
    Contact newContact;

    promptForContactInfo(newContact);
    if(contactCount < 8)
    {

        contacts[contactCount] = newContact;
        contactCount++;
    }
    else
    {
     
        contacts[oldestIndex] = newContact;
        oldestIndex = (oldestIndex + 1) % 8;
    }
    std::cout << " Yayy Contact added successfully!" << std::endl;

}



void PhoneBook::searchContact() const
{
    if(contactCount == 0)
    {
        std::cout << "PhoneBook is empty!"<< std::endl;
        return;
    }
    displayContactTable();

    std::cout << "\nEnter contact index to display (0-" << contactCount - 1 << "): ";
    std::string input;
    std::getline(std::cin, input);

    if(input.empty())
    {
        std::cout << "Invalid Index!" << std::endl;
        return;
    }
    for(size_t i = 0; i < input.length(); i++)
    {
        if(!std::isdigit(input[i]))
        {
            std::cout << "Invalid Index! Must be a number." << std::endl;
            return;
        }
    }

    //convert to int
    int index = 0;

    for (size_t i = 0; i < input.length(); i++)
    {
        index = index * 10 + (input[i] - '0');
        if(index > 7)
            break;
    }

    if(index < 0 || index >= contactCount)
    {
        std::cout << "Invalid index! Out of range." << std::endl;
        return;
    }
    displayContactDetails(index);

}
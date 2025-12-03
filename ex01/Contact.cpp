
#include "Contact.hpp"
#include <string>

Contact::Contact() : firstName(""), lastName(""), nickName(""),
                    phoneNumber(""), darkestSecret("") {}


//GETTERS

std::string Contact::getFirstName() const 
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickName() const
{
    return nickName;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}
std::string Contact::getDarkestSecret() const 
{
    return darkestSecret;
}

//SETTERS
void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
    this->nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}


bool Contact::isEmpty() const
{
    return (firstName.empty() && lastName.empty() &&
            nickName.empty() && phoneNumber.empty() && 
            darkestSecret.empty());
}
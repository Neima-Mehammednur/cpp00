
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;
    
    std::cout << "=== My Awesome PhoneBook ===" << std::endl;
    std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true)
    {
        std::cout << "\n> ";
        std::getline(std::cin, command);
        
        // Handle Ctrl+D
        if (std::cin.eof())
        {
            std::cout << std::endl;
            break;
        }
        
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
            break;
        else if (!command.empty())
            std::cout << "Invalid command. Use: ADD, SEARCH, EXIT" << std::endl;
    }
    
    std::cout << "Goodbye! Contacts are lost forever!" << std::endl;
    return 0;
}
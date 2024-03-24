#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <queue>
#include <iostream>
#include <string>
#include <iomanip>
/*
FIRST IN FIRST OUT = QUEUE
*/

class PhoneBook
{
	private:
		static const int MAX_CONTACTS = 8;
		std::queue<Contact> contacts;

	public:
	PhoneBook(){};
	void add()
	{
		Contact newContact;
		std::string input;

		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		while(input.length() == 0)
		{
			std::cout << "Enter first name: ";
			std::getline(std::cin, input);
		}
		newContact.setFirstname(input);

		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		while(input.length() == 0)
		{
			std::cout << "Enter last name: ";
			std::getline(std::cin, input);
		}
		newContact.setLastname(input);

		std::cout << "Enter nick name: ";
		std::getline(std::cin, input);
		while(input.length() == 0)
		{
			std::cout << "Enter nick name: ";
			std::getline(std::cin, input);
		}
		newContact.setNickname(input);
		std::cout << "Enter number: ";
		std::getline(std::cin, input);// add atoi and number check
		while(input.length() == 0 || !this->ft_isNumber(input))
		{
			std::cout << "Enter number: ";
			std::getline(std::cin, input);
		}
		newContact.setNumber(input);
		if(contacts.size() >= MAX_CONTACTS)
			contacts.pop();
		contacts.push(newContact);
	}
	void print() {
		// Create a temporary queue to store elements temporarily
		std::queue<Contact> tempQueue = contacts;

		// Loop through the temporary queue and print each element
		while (!tempQueue.empty()) {
			std::cout << tempQueue.front().getFirstname() << " | ";
			std::cout << tempQueue.front().getLastname() << " | ";
			tempQueue.pop();
		}
		std::cout << std::endl;
	}

bool	ft_isNumber(const std::string &number)
{
	// int i;
	// i = 0;
	// while(i < number.length())
	// {
	// 	if(!std::isdigit(number[i]))
	// 		return(false);
	// }
	// return(true)
	for(size_t i = 0; i < number.length(); ++i)
	{
		if(!std::isdigit(number[i]))
			return(false);
	}
	return(true);
}

};



#endif
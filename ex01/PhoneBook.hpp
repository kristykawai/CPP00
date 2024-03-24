#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook
{
	private:
		static const int MAX_CONTACTS = 8;
		Contact contacts[MAX_CONTACTS];
		int numContacts;

public:
	PhoneBook() : numContacts(0){};
	void add()
	{
		Contact newContact;
		if(numContacts < MAX_CONTACTS)
		{
			Contact newContact;
			std::string input;

			std::cout << "Enter first name: ";
			std::getline(std::cin, input);
			newContact.setFirstname(input);

			std::cout << "Enter last name: ";
			std::getline(std::cin, input);
			newContact.setLastname(input);

			std::cout << "Enter number: ";
			std::getline(std::cin, input);// add atoi and number check
			newContact.setNumber(input);

			contacts[numContacts] = newContact;
			numContacts++;
		}
		else 
			std::cout << "Phone book is full. Replacing the oldest entry." << std::endl; // change to replace the oldeest entry
	}

};

#endif
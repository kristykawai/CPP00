#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook
{
	private:
		static const int MAX_CONTACTS = 8; //change back to 8 at the end
		std::queue<Contact> contacts; //first in first out

	public:
	PhoneBook(){};
	//Member functions declaration
	void	ADD(void);
	void 	SEARCH(void);
	bool	ft_isNumber(const std::string &number);
	void 	EXIT(void);
	bool	ft_validateInput(const std::string& input);

};

//Member functions definitions
void PhoneBook::ADD(void)
{
	Contact newContact;
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	while(!ft_validateInput(input))
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
	}
	newContact.setFirstname(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	while(!ft_validateInput(input))
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
	}
	newContact.setLastname(input);

	std::cout << "Enter nick name: ";
	std::getline(std::cin, input);
	while(!ft_validateInput(input))
	{
		std::cout << "Enter nick name: ";
		std::getline(std::cin, input);
	}
	newContact.setNickname(input);

	std::cout << "Enter number: ";
	std::getline(std::cin, input);// add atoi and number check
	while(!ft_validateInput(input) || !ft_isNumber(input))
	{
		std::cout << "Enter number: ";
		std::getline(std::cin, input);
	}
	newContact.setNumber(input);

	std::cout << "Enter dark secret: ";
	std::getline(std::cin, input);
	while(!ft_validateInput(input))
	{
		std::cout << "Enter dark secret: ";
		std::getline(std::cin, input);
	}
	newContact.setDarksecrect(input);

	if(contacts.size() >= MAX_CONTACTS)
		contacts.pop();
	contacts.push(newContact);
}

void PhoneBook::SEARCH()
{
	// Create a temporary queue to store elements temporarily
	std::queue<Contact> tempQueue = contacts;

	// print column name
	 std::cout	<< std::setw(10) << std::right << "Index" << "|"
				<< std::setw(10) << std::right << "First Name" << "|"
				<< std::setw(10) << std::right << "Last Name" << "|"
				<< std::setw(10) << std::right << "Nickname" << std::endl;
	std::cout << std::setfill('-') << std::setw(44) << "" << std::endl;
	std::cout << std::setfill(' ');
	int index;
	index = 0;
	while (!tempQueue.empty())
	{
		std::string firstname = tempQueue.front().getFirstname();
		std::string lastname = tempQueue.front().getLastname();
		std::string nickname = tempQueue.front().getNickname();
	
		// Truncate strings longer than 10 characters
		if (firstname.length() > 10) firstname = firstname.substr(0, 9) + ".";
		if (lastname.length() > 10) lastname = lastname.substr(0, 9) + ".";
		if (nickname.length() > 10) nickname = nickname.substr(0, 9) + ".";

 	std::cout	<< std::setw(10) << std::right << index << "|"
				<< std::setw(10) << std::right << firstname << "|"
				<< std::setw(10) << std::right << lastname << "|"
				<< std::setw(10) << std::right << nickname << std::endl;
		tempQueue.pop();
		index++;
	}

	int selected_index;
	std::cout << "Enter the index of the entry to display: ";
	std::cin >> selected_index;
	if(selected_index >= 0 && selected_index < (int) contacts.size())
	{
		std::queue<Contact> tempQueue2 = contacts;
		for (int i = 0; i < selected_index; ++i)
		{
			tempQueue2.pop();
		}
		// print Contact Information
		std::cout << "Contact Information:" << std::endl;
		std::cout << "First Name: " << tempQueue2.front().getFirstname() << std::endl;
		std::cout << "Last Name: " << tempQueue2.front().getLastname() << std::endl;
		std::cout << "Nickname: " << tempQueue2.front().getNickname() << std::endl;
		std::cout << "Number: " << tempQueue2.front().getNumber() << std::endl;
		std::cout << "Dark Secret: " << tempQueue2.front().getDarksecret() << std::endl;
	}
	else
		std::cout << "Please enter a valid index between 0 to 7." << std::endl;
}

bool PhoneBook::ft_isNumber(const std::string &number)
{
	for(size_t i = 0; i < number.length(); ++i)
	{
		if(!std::isdigit(number[i]))
			return(false);
	}
	return(true);
}

void PhoneBook::EXIT(void)
{
	exit(EXIT_SUCCESS);
}

bool PhoneBook::ft_validateInput(const std::string& input)
{
	if(input.find_first_not_of(' ') != std::string::npos)
		return true;
	else
		std::cout << "field cannot be empty. Please try again." << std::endl;
		return false;
}

#endif

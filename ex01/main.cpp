/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:38:47 by kawai             #+#    #+#             */
/*   Updated: 2024/03/30 22:56:55 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This phonebook only accepts three commands: ADD, SEARCH, or EXIT.
	To clear the input buffer after the SEARCH function is used,
	std::cin.ignore is added. 
	We call std::getline() after std::cin,
	and "\n" is left in the buffer from the previous input operation.
*/

#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;

	while(1)
	{
		std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
		std::string command;
		std::getline(std::cin, command);
		
		if (command == "ADD")
			phoneBook.ADD();
		else if (command == "SEARCH")
		{
			phoneBook.SEARCH();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (command == "EXIT")
			phoneBook.EXIT();
	}
	return (0);
}

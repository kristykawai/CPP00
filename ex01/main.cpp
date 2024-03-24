/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:38:47 by kawai             #+#    #+#             */
/*   Updated: 2024/03/24 22:14:34 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            phoneBook.add();
		else if (command == "SEARCH")	
			phoneBook.print();
		else if (command == "EXIT")
			return (0);
	}
	return (0);
}
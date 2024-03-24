/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:38:47 by kawai             #+#    #+#             */
/*   Updated: 2024/03/24 12:01:42 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;

	while(1)
	{
		std::cout << "Commands: ADD, SEARCH, PRINT, EXIT" << std::endl;
        std::string command;
        std::getline(std::cin, command);
		if (command == "ADD")
		{
            phoneBook.add();
		}
	}
	return 0;
}
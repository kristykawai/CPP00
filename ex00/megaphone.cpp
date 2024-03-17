/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:45:36 by kawai             #+#    #+#             */
/*   Updated: 2024/03/17 23:47:29 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <cctype> 

int main(int ac, char *argv[])
{
	int i;
	int j;

	i = 1;
	if(ac > 1)
	{
		while(i < ac)
		{
			j = 0;
			while(argv[i][j]!= '\0')
			{		
		 		if(isalpha(argv[i][j]))
					std::cout << static_cast<char>(std::toupper(argv[i][j]));
				else if(!isspace(argv[i][j]))
					std::cout << (argv[i][j]);
				j++;
			}
			if (i != ac - 1)
				std::cout << " ";
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}

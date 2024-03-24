# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

/*
	setter and getter function to access content in private field
	use & reference allows the function directly access the original std::string object passed as an arguement rather than creating a copy of it.
*/

class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string number;
		int index;
	public:
		Contact() : index(-1){};

		void	setFirstname(const std::string& first) {firstname = first;}
		void	setLastname(const std::string& last) {lastname = last;}
		void	setNumber(const std::string& num) {number = num;}
		void	setIndex(int id){index = id;}

		std::string getFirstname() const {return firstname;}
		std::string getLastname() const {return lastname;}
		std::string getNumber() const {return number;}
		int getIndex() const {return index;}
};

#endif
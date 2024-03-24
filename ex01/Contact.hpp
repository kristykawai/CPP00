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
		std::string nickname;
		std::string darksecret;
		std::string number;
		// int index;
	public:
		// Contact() : index(-1){};
		// Default constructor
		Contact() : firstname(""), lastname(""), nickname(""), darksecret(""), number("") {}
		// Parameterized constructor
		Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& dark, const std::string& num)
		{
			firstname = first;
			lastname = last; 
			nickname = nick;
			darksecret = dark;
			number = num;
		};

		void	setFirstname(const std::string& first) {firstname = first;}
		void	setLastname(const std::string& last) {lastname = last;}
		void	setNickname(const std::string& nick) {nickname = nick;}
		void	setDarksecrect(const std::string& dark) {darksecret = dark;}
		void	setNumber(const std::string& num) {number = num;}
		// void	setIndex(int id){index = id;}

		std::string getFirstname() const {return firstname;}
		std::string getLastname() const {return lastname;}
		std::string getNickname() const {return nickname;}
		std::string getDarksecret() const {return darksecret;}
		std::string getNumber() const {return number;}
		// int getIndex() const {return index;}
};

#endif
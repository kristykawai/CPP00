NAME := phonebook
HEADERS := Phonebook.hpp Contact.hpp
SCRS := main.cpp
OBJS := $(SCRS:%.cpp=%.o)

CC := c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

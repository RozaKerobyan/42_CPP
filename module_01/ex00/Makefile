NAME    = Zombie
CPP      = c++
CPP_FLAGS  = -Wall -Wextra -Werror -std=c++98
SRCS    = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
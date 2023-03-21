PHILO = main.c utils.c check_input.c thread_phil.c better_sleep.c

CC = @gcc

FLAGS = -pthread -Wall -Werror -Wextra

PHILO_NAME = philo

PHILO_SRC = $(PHILO)

PHILO_OBJS = $(PHILO_SRC:.c=.o)

all: $(PHILO_NAME)

philo: $(PHILO_OBJS)
	@$(CC) $(FLAGS) $(PHILO_OBJS) -o $(PHILO_NAME)

bonus: all

clean:
	@rm -rf $(PHILO_OBJS)

fclean: clean
	@rm -rf $(PHILO_NAME)

re: fclean all
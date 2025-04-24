RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
BLUE = $(shell printf "\33[34m")
YELLOW = $(shell printf "\33[33m")
WHITE  = $(shell printf "\33[37m")
PURPLE = $(shell printf "\33[35m")
RESET  = $(shell printf "\33[0m")



HEADER			=	philo.h

SOURCES			=	validation_utils.c \
					main.c \
					initialization.c \
					time_utils.c \
					dinner_manager.c \
					philosopher_monitor.c \
					philosopher_action.c \
					philosopher_utils.c \
					

OBJECTS			= $(SOURCES:.c=.o)

NAME			=	philo

CC				=	cc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -g

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJECTS) $(HEADER)
		@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
		@echo "$(BLUE)"
		@echo "██████╗  ██╗  ██╗ ██╗ ██╗      ██████╗   ██████╗  ██████╗  ██████╗  ██╗  ██╗ ██████╗ ██████╗  ██████╗"
		@sleep 0.1
		@echo "██╔══██╗ ██║  ██║ ██║ ██║     ██╔═══██╗ ██╔════╝ ██╔═══██╗ ██╔══██╗ ██║  ██║ ██╔═══╝ ██╔══██╗ ██╔════╝"
		@sleep 0.1
		@echo "██████╔╝ ███████║ ██║ ██║     ██║   ██║  █████╗  ██║   ██║ ██████╔╝ ███████║ ██████╗ ██████╔╝  █████╗"
		@sleep 0.1
		@echo "██╔═══╝  ██╔══██║ ██║ ██║     ██║   ██║  ╚═══██╗ ██║   ██║ ██╔═══╝  ██╔══██║ ██╔═══╝ ██╔══██╗  ╚═══██╗"
		@sleep 0.1
		@echo "██║      ██║  ██║ ██║ ██████╗  ██████╔╝ ██████╔╝  ██████╔╝ ██║      ██║  ██║ ██████╗ ██   ██╗ ██████╔╝"
		@sleep 0.1
		@echo "╚═╝      ╚═╝  ╚═╝ ╚═╝ ╚═════╝  ╚════╝  ╚═════╝    ╚════╝   ╚═╝      ╚═╝  ╚═╝ ╚═════╝ ╚═══╚══╝ ╚═════╝"
		@sleep 0.1
		@echo
		@echo "                                    	  ℹ️ $(RED) DONE 🍽️.$(RESET)"
		@echo



clean:
	@$(RM) $(OBJECTS)
	@clear 
	@echo 
	@echo "$(RED)CLEANED$(RESET)"
	@echo

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all
		@echo "                                      ℹ️ $(YELLOW) Dinner is ready! 🍽️.$(RESET)"
		@sleep 0.1
		@echo
		@sleep 0.1
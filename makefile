RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
BLUE = $(shell printf "\33[34m")
YELLOW = $(shell printf "\33[33m")
WHITE  = $(shell printf "\33[37m")
PURPLE = $(shell printf "\33[35m")
RESET  = $(shell printf "\33[0m")

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

HEADER			=	$(INC_DIR)/philo.h

SRC_FILES = $(SRC_DIR)/validation_utils.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/initialization.c \
			$(SRC_DIR)/time_utils.c \
			$(SRC_DIR)/dinner_manager.c \
			$(SRC_DIR)/philosopher_monitor.c \
			$(SRC_DIR)/philosopher_action.c \
			$(SRC_DIR)/philosopher_utils.c \
			$(SRC_DIR)/forks_mutex.c


OBJECTS = $(OBJ_DIR)/validation_utils.o \
		  $(OBJ_DIR)/main.o \
		  $(OBJ_DIR)/initialization.o \
		  $(OBJ_DIR)/time_utils.o \
		  $(OBJ_DIR)/dinner_manager.o \
		  $(OBJ_DIR)/philosopher_monitor.o \
		  $(OBJ_DIR)/philosopher_action.o \
		  $(OBJ_DIR)/philosopher_utils.o \
		  $(OBJ_DIR)/forks_mutex.o

NAME = $(BIN_DIR)/philo

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR)

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@clear
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
	@echo "                                    ⏱️ $(BLUE) READY TO EAT 🍕.$(RESET)"
	@echo
	@echo
	@echo
	@echo "				$(PURPLE)Try: ./bin/philo 5 500 600 800 $(RESET)"
	@echo
	@echo

clean:
	@$(RM) $(OBJECTS)
	@clear 
	@echo 
	@echo "$(RED)CLEANED$(RESET)"
	@echo 
	@sleep 0.5
	@clear

fclean: clean
	@$(RM) $(NAME)

re: fclean	all
	

.PHONY: all clean fclean re
MINITALK_SRC_PATH = src
MINITALK_INC_PATH = inc

# Define source files
SERVER = $(MINITALK_SRC_PATH)/server.c
CLIENT = $(MINITALK_SRC_PATH)/client.c

# Object files
SERVER_OBJS = $(SERVER:.c=.o)
CLIENT_OBJS = $(CLIENT:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(MINITALK_INC_PATH)

# Executable names
SERVER_NAME = server
CLIENT_NAME = client

# Targets
all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJS) -o $@

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJS) -o $@

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

# Pattern rule to compile .c to .o
$(MINITALK_SRC_PATH)/%.o: $(MINITALK_SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re

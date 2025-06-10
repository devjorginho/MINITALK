# Paths
MINITALK_SRC_PATH = src
MINITALK_INC_PATH = inc

# Files
SERVER = $(MINITALK_SRC_PATH)/server.c
CLIENT = $(MINITALK_SRC_PATH)/client.c

# Objects
SERVER_OBJS = $(SERVER:.c=.o)
CLIENT_OBJS = $(CLIENT:.c=.o)

# Compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES =-I$(MINITALK_INC_PATH)

# Executables names
SERVER_NAME = server
CLIENT_NAME = client

# ---------------- Rules --------------------

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)

clean:
	$(MAKE) -C $(FT_PRINTF_PATH) clean
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(MAKE) -C fclean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

# Compile .c to .o
$(MINITALK_SRC_PATH)/%.o: $(MINITALK_SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re

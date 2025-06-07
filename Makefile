# Paths
FT_PRINTF_PATH = ft_printf
MINITALK_SRC_PATH = src
MINITALK_INC_PATH = inc

# Files
SERVER = $(MINITALK_SRC_PATH)/server.c
CLIENT = $(MINITALK_SRC_PATH)/client.c

# Lib ft_printf
LIBFT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

# Objects
SERVER_OBJS = $(SERVER:.c=.o)
CLIENT_OBJS = $(CLIENT:.c=.o)

# Compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(FT_PRINTF_PATH) -I$(MINITALK_INC_PATH)

# Executables names
SERVER_NAME = server
CLIENT_NAME = client

# ---------------- Rules --------------------

all: $(LIBFT_PRINTF) $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT_PRINTF) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_PRINTF) -o $(CLIENT_NAME)

clean:
	$(MAKE) -C $(FT_PRINTF_PATH) clean
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

# Compile .c to .o
$(MINITALK_SRC_PATH)/%.o: $(MINITALK_SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re

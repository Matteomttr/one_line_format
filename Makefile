# The name of the one_line_format archive
NAME= one_line_format

# Compiler + flags for executable
CC= cc
CFLAGS= -Wall -Werror -Wextra

# Compiler + flags for archive
AR= ar
ARFLAGS= rsc

# Source and object directories
SRC_DIR= src
OBJ_DIR= obj

# List of archive files
ARS=	$(SRC_DIR)/libft/ft_dprintf/libft_dprintf.a \

# List of src files
SRCS=	$(SRC_DIR)/main.c \

# List of obj files
OBJS=	$(OBJ_DIR)/main.o \

# Compile everything
all: $(NAME)

# Compile everything into an archive
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(ARS) -o $(NAME)
	@echo "Executable created successfully!"

# Compile src files into obj files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up obj files
clean:
	@rm -f $(OBJS)
	@echo "Object successfully deleted!"

# Clean up obj files and archive
fclean: clean
	@rm -f $(NAME)
	@echo "Executable successfully deleted!"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
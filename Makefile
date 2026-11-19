# The name of the one_line_format executable
NAME= one_line_format

# Compiler + flags for executable
CC= cc
CFLAGS= -Wall -Wextra -Werror -g

# Source, object and library directories
SRC_DIR= src
OBJ_DIR= obj
DPRINTF_DIR= $(SRC_DIR)/libft/ft_dprintf

# List of archive files
DPRINTF= $(DPRINTF_DIR)/libft_dprintf.a

# List of include directories
INCLUDES= -I$(SRC_DIR) \
			-I$(SRC_DIR)/get_next_line \
			-I$(DPRINTF_DIR)

# List of src files
SRCS= $(SRC_DIR)/main.c \
		$(SRC_DIR)/ft_parse_file.c \
		$(SRC_DIR)/ft_format_text.c \
		$(SRC_DIR)/get_next_line/get_next_line.c \
		$(SRC_DIR)/get_next_line/get_next_line_utils.c

# List of obj files (derived from SRCS, keeps subdirectories)
OBJS= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compile everything
all: $(NAME)

# Compile everything into an executable (builds the archive first)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(DPRINTF) -o $(NAME)
	@echo "Executable created successfully!"

# Compile src files into obj files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up obj files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object successfully deleted!"

# Clean up obj files and executable
fclean: clean
	@rm -f $(NAME)
	@echo "Executable successfully deleted!"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

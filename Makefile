NAME = minirt
CC = gcc
OBJDIR = objs
INCLUDES = -I ./includes/
FRAMEWORK =  -lmlx -framework OpenGL -framework AppKit
# FRAMEWORK =  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
CFLAGS = -pthread #-Wall -Wextra -Werror
SRC = 	$(wildcard parser/*.c) \
		$(wildcard utils/*.c) \
		$(wildcard libft/*.c) \
		$(wildcard get_line/*.c) \
		$(wildcard instances/*.c) \
		$(wildcard render/*.c) \
		$(wildcard resources/*.c) \
		$(wildcard *.c)

OBJ =   $(patsubst %.c, %.o, $(SRC))
INDIR = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))
MKDIR = mkdir -p 

$(OBJDIR)/%.o : %.c ./includes/*.h
	@ $(MKDIR) $(OBJDIR)/parser
	@ $(MKDIR) $(OBJDIR)/utils
	@ $(MKDIR) $(OBJDIR)/instances
	@ $(MKDIR) $(OBJDIR)/libft
	@ $(MKDIR) $(OBJDIR)/get_line
	@ $(MKDIR) $(OBJDIR)/render
	@ $(MKDIR) $(OBJDIR)/resources
	@ $(CC) $(CFLAGS) $(INCLUDES) -Imlx -c $< -o $@ 

all : $(NAME)

$(NAME) : $(INDIR) 
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(INDIR) $(FRAMEWORK) $(INCLUDES) -o $(NAME)
	@echo "Compiled..."

re : fclean all

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)
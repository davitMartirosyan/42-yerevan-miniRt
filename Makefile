NAME = minirt
CC = gcc
OBJDIR = objs
INCLUDES = -I ./includes/
#FRAMEWORK =  -lmlx -framework OpenGL -framework AppKit
FRAMEWORK =  -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CFLAGS = -lm #-Wall -Wextra -Werror
SRC = 	$(wildcard parser/*.c) \
		$(wildcard unreal/*.c) \
		$(wildcard render/*.c) \
		$(wildcard utils/*.c) \
		$(wildcard components/*.c)\
		$(wildcard tracer/*.c) \
		$(wildcard vector/*.c) \
		$(wildcard libft/*.c) \
		$(wildcard get_line/*.c) \
		$(wildcard *.c)

OBJ =   $(patsubst %.c, %.o, $(SRC))
INDIR = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))
MKDIR = mkdir -p 

$(OBJDIR)/%.o : %.c
	@ $(MKDIR) $(OBJDIR)/parser
	@ $(MKDIR) $(OBJDIR)/unreal
	@ $(MKDIR) $(OBJDIR)/vector
	@ $(MKDIR) $(OBJDIR)/components
	@ $(MKDIR) $(OBJDIR)/tracer
	@ $(MKDIR) $(OBJDIR)/render
	@ $(MKDIR) $(OBJDIR)/utils
	@ $(MKDIR) $(OBJDIR)/libft
	@ $(MKDIR) $(OBJDIR)/get_line
	@$(CC) $(CFLAGS) $(INCLUDES) -Imlx_linux -c $< -o $@ 

all : $(NAME)

$(NAME) : $(INDIR)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(INDIR) $(INCLUDES) $(FRAMEWORK) -o $(NAME)
	@echo "Compiled..."



re : fclean all

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)
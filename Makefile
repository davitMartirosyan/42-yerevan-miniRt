NAME = minirt
CC = gcc
OBJDIR = objs
INCLUDES = -I ./includes/
FRAMEWORK =  -lmlx -framework OpenGL -framework AppKit
#FRAMEWORK =  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
CFLAGS = -Wall -Wextra -Werror
SRC = 	$(wildcard parser/*.c) \
		$(wildcard unreal/*.c) \
		$(wildcard render/*.c) \
		$(wildcard utils/*.c) \
		$(wildcard components/*.c)\
		$(wildcard tracer/*.c) \
		$(wildcard vector/*.c) \
		$(wildcard libft/*.c) \
		$(wildcard gnl/*.c) \
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
	@ $(MKDIR) $(OBJDIR)/gnl
	@$(CC) $(CFLAGS) $(INCLUDES) -Imlx -c $< -o $@ 

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
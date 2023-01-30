NAME = minirt
CC = gcc
OBJDIR = objs
INCLUDES = -I ./includes/
FRAMEWORK = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm  #-framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
SRC = 	$(wildcard parser/*.c) \
		$(wildcard unreal/*.c) \
		$(wildcard render/*.c) \
		$(wildcard utils/*.c) \
		$(wildcard components/*.c)\
		$(wildcard tracer/*.c) \
		$(wildcard vector/*.c) \
		$(wildcard libft/*.c) \
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
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

all : $(NAME)

$(NAME) : $(INDIR)
	$(CC) $(CFLAGS) $(INDIR) $(FRAMEWORK) $(INCLUDES) -o $(NAME)

re : fclean all

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)
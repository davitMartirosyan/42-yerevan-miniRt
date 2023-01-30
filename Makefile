NAME = minirt
CC = gcc
OBJDIR = objs
INCLUDES = -I ./includes/
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard parser/*.c) $(wildcard render/*.c) $(wildcard utils/*.c) $(wildcard vector/*.c) $(wildcard libft/*.c)

OBJ =   $(patsubst %.c, %.o, $(SRC))
INDIR = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))
MKDIR = mkdir -p 

$(OBJDIR)/%.o : %.c
	@ $(MKDIR) $(OBJDIR)/parser
	@ $(MKDIR) $(OBJDIR)/vector
	@ $(MKDIR) $(OBJDIR)/render
	@ $(MKDIR) $(OBJDIR)/utils
	@ $(MKDIR) $(OBJDIR)/libft
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

all : $(NAME)

$(NAME) : $(INDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(INDIR) -o $(NAME)

fclean :
	rm -rf $(OBJDIR)
	rm -rf $(NAME)
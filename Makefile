
# Nom de l'exécutable
NAME = cub3d

# Dossiers
SRCDIR = .
GNLDIR = gnl
LIBFTDIR = libft
OBJDIR = obj

# Fichiers sources
SRC = $(wildcard $(SRCDIR)/*.c) $(wildcard $(GNLDIR)/*.c)
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Drapeaux du compilateur
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -L$(LIBFTDIR) -lft

# Commandes
RM = rm -rf

# Compilation de l'exécutable
$(NAME): $(OBJ) $(LIBFTDIR)/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

# Création des fichiers objets
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation de la libft
$(LIBFTDIR)/libft.a:
	make -C $(LIBFTDIR)

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFTDIR) clean

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

# Recompilation complète
re: fclean $(NAME)

# Pas de relink inutile
.PHONY: clean fclean re all
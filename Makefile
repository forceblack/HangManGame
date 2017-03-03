# En général dans un Makefile on commence par définir tout un
# tas de variables qui nous serviront ensuite.
# L'avantage est de pouvoir copier/coller le fichier et de n'avoir
# quasiment rien à modifier pour un autre programme.

# Compilateur à utiliser
CC ?= gcc

# Nom du binaire à généré
TARGET = HangMan

# Liste des fichiers à compiler
SOURCES = DisplayHM.c GameHM.c Dico.c LogicHM.c main.c

# Permet d'avoir la liste des fichiers avec l'extension .o
OBJECTS = $(SOURCES:.c=.o)

# Flags de compilation : permet de configurer le comportement de gcc
# Exemples :
#   - Activer tout les warning : -Wall
#   - Considérer les warning comme des erreurs : -Werror
#   - Ajouter les information de débug pour GDB : -g -ggdb
#   - Choisir le niveau d'optimisation : -O[0,1,2,3]
# Aussi il se peut que dans l'environnement du shell linux
# la variable CFLAGS soit déjà définie. Il est une bonne pratique
# de l'inclure ici.
C_FLAGS = $(CFLAGS) -Wall -Werror -g -ggdb -O0

# Flags de linkage : permet de configurer le comportement de ld
# Exemples :
#   - Ajouter une bibliothèque : -lmy_lib
# Comme pour C_FLAGS, il existe une variable d'environnement un
# peu standard LDFLAGS déjà définie.
LD_FLAGS = $(LDFLAGS)

all: $(TARGET)

# Un makefile est un fichier qui décrit des régles.
# Ces régles sont simplement une liste de commandes à éxécuter.
# Elles ont aussi une liste de dépendances qui permettent à make
# de savoir dans quel ordre éxécuter les régles.
# Il existe plusieurs façon de déclarer des régles.
# La plus classique est :
compile_ex1:
	gcc -o HangMan -Wall -Werror -g -ggdb -O0 DisplayHM.c GameHM.c Dico.c LogicHM.c main.c

# Ce qui n'est absolument pas réutilisable pour un autre programme.
# D'où l'utilisation de variables plutôt :
compile_ex2:
	$(CC) -o $(TARGET) $(C_FLAGS) $(SOURCES) $(LD_FLAGS)

# Comme dit avant, on peut aussi ajouter des dépendances aux régles.
# Cela permet à make de lancer la régle requise ou de vérifier
# que un ou plusieurs fichiers existent déjà.
# Ici, on va dépendre des fichier c. Ce qui permet à make
# d'afficher une erreur si un fichier est manquant.
compile_ex3: $(SOURCES)
	$(CC) -o $(TARGET) $(C_FLAGS) $(SOURCES) $(LD_FLAGS)

# On peut aussi définir des régles génériques par type de fichier
# Comme ça si make ne trouve pas un fichier, il a une régle pour
# le fabriquer.
# Ici, pour chaque fichier .c on va créer un fichier .o qui est la
# version compilé de juste ce fichier. Ce n'est pas encore le programme
# mais ça permet à make d'éviter de recompiler ce qui n'a pas changé.
# Pour des projets avec plusieurs milliers de fichier, c'est très pratique.
# $< et $@ sont des variables spéciales de make. Elle correspondent au nom
# des fichiers : $< pour le .c et $@ pour le .o ici
%.o:%.c
	$(CC) $(C_FLAGS) -c $< -o $@

# On peut aussi utiliser une variable comme nom de régle, ce qui permet de
# faire "make HangMan" en ligne de commande.
# Ici, comme on a la régle pour compiler chaque fichier .o, on définit la
# régle pour compiler le programme.
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LD_FLAGS)

# Il y a aussi la régle all, que j'ai défini plus haut.
# make utilise la première régle qu'il trouve comme régle par défaut, c'est à dire
# qu'il l'utilisera si aucune n'est passé en paramètre de la ligne de commande.
# On définit donc généralement une régle all en premier qui correspond à ce que ce
# fichier est censé faire.

# Il existe la régle .PHONY qui permet de préciser à make d'éxécuter certaines
# régles même si même si il considère qu'il n'en a pas besoin.
# .PHONY: $(TARGET)

# Dernière bonne pratique, une régle clean, qui permet de nettoyer les fichiers
# de compilation et d'éviter de les laisser sur git ;).
clean:
	rm -rf *.o $(TARGET)

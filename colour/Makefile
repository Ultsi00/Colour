NAME = colour
SRCS =	srcs/main.cpp srcs/c_sdl.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(OBJS) -w -lSDL2 -lSDL2_image -o $(NAME)
#-r (recursive): deletes files before the folder
#-f (force): ignore non-existant files, and never prompt before removing.
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

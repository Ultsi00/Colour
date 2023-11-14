NAME = colour
SRCS =	srcs/main.cpp srcs/c_sdl.cpp srcs/c_draw.cpp srcs/program_loop.cpp \
		srcs/drawing.cpp srcs/fill_vector.cpp srcs/c_keyevent.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(OBJS) -w -lSDL2 -o $(NAME)
#-r (recursive): deletes files before the folder
#-f (force): ignore non-existant files, and never prompt before removing.
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

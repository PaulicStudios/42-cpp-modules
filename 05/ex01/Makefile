NAME	:=	form

CC		:=	c++
INCDIR	:=	inc
CFLAGS	:=  -Wextra -Wall -Werror -std=c++17

VPATH	:=	src
SOURCES	:=	Bureaucrat.cpp \
			Form.cpp \
			main.cpp

OBJDIR	:=	obj
OBJECTS	:=	$(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(INC)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

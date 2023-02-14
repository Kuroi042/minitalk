NAMEC = clients
NAMES = servers 

CC = gcc

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = server.c client.c 
cli = client.c 
ser = server.c
tool = tools.c 

all:
	$(RM) $(NAMEC) 
	$(RM) $(NAMES)
	
$(NAME): 
	$(CC) $(CFLAGS) $(SRC) $(tool)
server:
	$(CC) $(CFLAGS) $(ser) $(tool) -o $(NAMES)

client:
	$(CC) $(CFLAGS) $(cli) $(tool) -o $(NAMEC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

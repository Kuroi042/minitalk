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
	@$(RM) $(NAMEC) 
	@$(RM) $(NAMES)
	@echo "<<remove server && client >>"
	
$(NAME): 
	@$(CC) $(CFLAGS) $(SRC) $(tool)
server:
	@$(CC) $(CFLAGS) $(ser) $(tool) -o $(NAMES)
	@echo "<<server make succefully>>"


client:
	@$(CC) $(CFLAGS) $(cli) $(tool) -o $(NAMEC)
	@echo "<<client make succefully>>"
clean:
	@$(RM) $(OBJ)
	@echo "<<cleaning ob succefully>>"

fclean:
	@$(RM) $(NAME)
	@echo "<<cleaning ob file succefully>>"

re: fclean all

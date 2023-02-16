#NAMEC = client
NAMES = server
NAMEC = client
NAMEEC = client_bonus
NAMEES = server_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = server.c client.c
SRCB = server_bonus.c client_bonus.c 
cli = client.c 
clib = client_bonus.c
ser = server.c
serb = server_bonus.c
tool = tools.c 
OBJ = $(SRC: .c=.o)

all: $(NAMES) $(NAMEC)

 	
$(NAME):
	@$(CC) $(CFLAGS) $(SRC) $(tools) -o $(NAMEC) $(NAMES)
	
server:
	@$(CC) $(CFLAGS) $(ser) $(tool) -o $(NAMES)
	@echo "<<server make succefully>>"
client:
	@$(CC) $(CFLAGS) $(cli) $(tool) -o $(NAMEC)
	@echo "<<client make succefully>>"


clean:
	@$(RM) $(NAMEC) $(NAMES)
	@echo "<<cleaning object succefully>>"

fclean: clean
	@$(RM) $(NAMEC) $(NAMES)
	@echo "<<cleaning executable succefully>>"

re: fclean all

##BONUS############################################

 bonus: $(NAMEEC) $(NAMEES)

$(NAMEBONUS): 
	@$(CC) $(CFLAGS) $(SRCB) $(tool) -o $(NAMEEC) $(NAMEES)

client_bonus:
	@$(CC) $(CFLAGS) $(clib) $(tool) -o $(NAMEEC)
	@echo "<<client_bonus build succefully>>"
server_bonus:
	@$(CC) $(CFLAGS) $(serb) $(tool) -o $(NAMEES)
	@echo "<<server_bonus build succefully>>"	
cleanbonus:
	@$(RM) $(NAMEEC) $(NAMEES)
	@echo "<<cleaning objectfile bonus succefully>>"
fcleanbonus : clean bonus
	@$(RM) $(NAMEEC) $(NAMEES)
	@echo "<<cleaning executable bonus succefully>>"
rebonus: fcleanbonus bonus

##BONUS##################################################
##BONUS###############################################




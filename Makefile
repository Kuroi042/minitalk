#mandatory exec
NAMES = server 
NAMEC = client

#bonus exec
NAMEES = server_bonus
NAMEEC = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#SRC
SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_TOOLS = tools.c
SRC_SERVER_B = server_bonus.c
SRC_CLIENT_B = client_bonus.c

#OBJ
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_TOOLS = $(SRC_TOOLS:.c=.o)
OBJ_SERVER_B = $(SRC_SERVER_B:.c=.o)
OBJ_CLIENT_B = $(SRC_CLIENT_B:.c=.o)

SERVER_B = server_bonus
CLIENT_B = client_bonus


all: $(NAMES) $(NAMEC)

##exeec
$(NAMEC): $(OBJ_CLIENT) $(OBJ_TOOLS)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_TOOLS) -o $(NAMEC)
	@echo "<<client make successfully>>"


$(NAMES): $(OBJ_SERVER) $(OBJ_TOOLS)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_TOOLS) -o $(NAMES)
	@echo "<<server make successfully>>"

###OBJ clt
$(OBJ_CLIENT): $(SRC_CLIENT) $(SRC_TOOLS)
	@$(CC) $(CFLAGS) -c $(SRC_CLIENT) $(SRC_TOOLS)


$(OBJ_SERVER): $(SRC_SERVER) $(SRC_TOOLS)
	@$(CC) $(CFLAGS) -c $(SRC_SERVER) $(SRC_TOOLS)


bonus: $(NAMEES) $(NAMEEC)

##bonus exec
$(NAMEEC): $(OBJ_CLIENT_B) $(OBJ_TOOLS)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT_B) $(OBJ_TOOLS) -o $(NAMEEC)
	@echo "<<client_bonus make successfully>>"


$(NAMEES): $(OBJ_SERVER_B) $(OBJ_TOOLS)
	@$(CC) $(CFLAGS) $(OBJ_SERVER_B) $(OBJ_TOOLS) -o $(NAMEES)
	@echo "<<server_bonus make successfully>>"

###bonus Objectf
$(OBJ_CLIENT_B): $(SRC_CLIENT_B) $(SRC_TOOLS)
	@$(CC) $(CFLAGS) -c $(SRC_CLIENT_B) $(SRC_TOOLS)

$(OBJ_SERVER_B): $(SRC_SERVER_B) $(SRC_TOOLS)
	@$(CC) $(CFLAGS) -c $(SRC_SERVER_B) $(SRC_TOOLS)


clean:
	@$(RM) $(NAMEC) $(NAMES) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_TOOLS)
	@echo "<<cleaning object successfully>>"

# rm  objectf +++ exec mandatory
fclean: clean
	@$(RM) $(NAMEC) $(NAMES)
	@echo "<<cleaning executable successfully>>"

# clean up bonus objectf
cleanbonus:
	@$(RM) $(NAMEEC) $(NAMEES) $(OBJ_CLIENT_B) $(OBJ_SERVER_B) $(OBJ_TOOLS)
	@echo "<<cleaning object successfully>>"

# rm bonus OF && ex
fcleanbonus: cleanbonus
	@$(RM) $(NAMEEC) $(NAMEES)
	@echo "<<cleaning executable successfully>>"

# msse7 kolchi bda mn 0
re: fclean all

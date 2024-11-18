# Compiler and flags
CC = gcc

# Targets
CLIENT = client
SERVER = server

# Default mode
all: $(CLIENT) $(SERVER)

# Compile to .o files
$(CLIENT): client.o
	$(CC) $(CFLAGS) -o $(CLIENT) client.o

$(SERVER): server.o
	$(CC) $(CFLAGS) -o $(SERVER) server.o

# Compile to .c files
client.o: client.c
	$(CC) $(CFLAGS) -c client.c

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

# Remove generated files
clean:
	rm -f *.o $(CLIENT) $(SERVER)

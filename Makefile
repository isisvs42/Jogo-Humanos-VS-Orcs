CC = g++
SRC = ./src
OBJS = ./objs
TARGET = Battle_Game
LIMPAR = rm

all: objetos
	$(CC) $(OBJS)/player.o $(OBJS)/functions.o $(OBJS)/main.o -o $(TARGET)
	

objetos:
	$(CC) -c $(SRC)/player.cpp -o $(OBJS)/player.o
	$(CC) -c $(SRC)/functions.cpp -o $(OBJS)/functions.o
	$(CC) -c main.cpp -o $(OBJS)/main.o


clear:
	$(LIMPAR) $(OBJS)/*.o
	$(LIMPAR) $(TARGET)
CC = g++
FLAGS =  -std=c++11 -Wall

all: game

# ---		MAKE THE GAME-FILE! 	---
game : player.o item.o scene.o main.o
	clear
	$(CC) $(FLAGS) item.o player.o scene.o main.o -o game
	./game

#---		CHARACTERS				---
main.o : main.cpp
	$(CC) $(FLAGS) -c main.cpp
#---		CHARACTERS				---
player.o : player.cpp player.hpp
	$(CC) $(FLAGS) -c player.cpp

#---		ITEMS					---
item.o : item.cpp item.hpp
	$(CC) $(FLAGS) -c item.cpp	

#---		SCENE					---
scene.o : scene.cpp scene.hpp
	$(CC) $(FLAGS) -c scene.cpp	

clean:
	rm *o
CC = g++
FLAGS =  -std=c++11 -Wall

all: game

# ---		MAKE THE GAME-FILE! 	---
game : player.o item.o scene.o main.o human.o animal.o
	clear
	$(CC) $(FLAGS) item.o player.o scene.o main.o human.o animal.o -o game
	./game

#---		MAIN 					---
main.o : main.cpp
	$(CC) $(FLAGS) -c main.cpp

#---		PLAYER 					---
player.o : player.cpp player.hpp
	$(CC) $(FLAGS) -c player.cpp

#---		ITEMS					---
item.o : item.cpp item.hpp
	$(CC) $(FLAGS) -c item.cpp	

#---		SCENE					---
scene.o : scene.cpp scene.hpp
	$(CC) $(FLAGS) -c scene.cpp	


#--------------------------------------
#---		VIRTUAL STUFF			---
#--------------------------------------


#---		HUMAN					---
human.o : player.cpp player.hpp human.cpp human.hpp
	$(CC) $(FLAGS) -c human.cpp	


#---		ANIMAL					---
animal.o : player.cpp player.hpp animal.cpp animal.hpp
	$(CC) $(FLAGS) -c animal.cpp	



clean:
	rm *o
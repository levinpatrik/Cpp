# all: mainTest.cpp
# 	clear
# 	g++ -g  -std=c++11 -o main.out mainTest.cpp Crab.cpp Ape.cpp Merchant.cpp Pirate.cpp Player.cpp Container.cpp Weapon.cpp Character.cpp
# 	./main.out



CC = g++
FLAGS = -std=c++11 -g -Wall

CHARACTERS_C = Ape.cpp Character.cpp Crab.cpp Merchant.cpp Pirate.cpp Player.cpp 
CHARACTERS_H = Ape.hpp Character.hpp Crab.hpp Merchant.hpp Pirate.hpp Player.hpp

ITEMS_C = Container.cpp Weapon.cpp Money.cpp 
ITEMS_H = Container.hpp Weapon.hpp Money.hpp


game.out : character.o item.o
	$(CC) $(FLAGS) -o game.out main.cpp 

character.o : $(CHARACTERS) 
	$(CC) $(FLAGS) -c 

item.o : Container.hpp Container.cpp mainItem.cpp Weapon.cpp Money.cpp 
	$(CC) $(FLAGS) -c item.out Container.cpp Weapon.cpp Money.cpp



clean:
	rm -f *.out
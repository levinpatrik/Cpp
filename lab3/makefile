CC = g++
FLAGS = -std=c++11 -g -Wall
# CHARACTERS = Ape.cpp Character.cpp Crab.cpp Merchant.cpp Pirate.cpp Player.cpp 

PATH_C = ./character/ 
# PATH_I = ./item/


# game.out : character.out item.out
# 	$(CC) $(FLAGS) -o game.out main.cpp 

character.out : $(CHARACTERS) mainTest.cpp
	$(CC) $(FLAGS) -o character.out $(CHARACTERS) mainTest.cpp

# $(PATH_I)item.out : $(PATH_I)Container.cpp mainItem.cpp Weapon.cpp Money.cpp
# 	$(CC) $(FLAGS) -o item.out Container.cpp Weapon.cpp Money.cpp



clean:
	rm -f *.out
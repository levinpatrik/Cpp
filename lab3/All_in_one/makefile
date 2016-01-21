# SCENE_CPP = Beach.cpp Cave.cpp Indoor.cpp Jungle.cpp Room.cpp Scene.cpp Outdoor.cpp
# CHARACTERS_CPP = Ape.cpp Character.cpp Crab.cpp Merchant.cpp Pirate.cpp Player.cpp
# ITEMS_CPP = Container.cpp Weapon.cpp Item.cpp

# all: mainTest.cpp
# 	clear
# 	g++ -g  -std=c++11 -o main.out mainTest.cpp $(SCENE_CPP) $(CHARACTERS_CPP) $(ITEMS_CPP)
# 	./main.out




# all: mainTest.cpp
# 	clear
# 	g++ -g  -std=c++11 -o main.out mainTest.cpp Crab.cpp Ape.cpp Merchant.cpp Pirate.cpp Player.cpp Container.cpp Weapon.cpp Character.cpp
# 	./main.out




CC = g++
FLAGS = -std=c++11 -Wall

SCENE_O = Beach.o Cave.o Indoor.o Jungle.o Room.o Scene.o Outdoor.o
CHARACTERS_O = Ape.o Character.o Crab.o Merchant.o Pirate.o Player.o
ITEMS_O = Container.o Weapon.o Item.o

SCENE_H = Beach.hpp Cave.hpp Indoor.hpp Jungle.hpp Room.hpp Scene.hpp Outdoor.hpp
ITEMS_H = Item.hpp Container.hpp Weapon.hpp Money.hpp
CHARACTERS_H = Ape.hpp Character.hpp Crab.hpp Merchant.hpp Pirate.hpp Player.hpp Animal.hpp Human.hpp


#	---		MAKE THE OUT-FILE! 	---
game.out : $(CHARACTERS_O) $(ITEMS_O) $(SCENE_O) mainTest.o
#	clear
	$(CC) $(FLAGS) $(CHARACTERS_O) $(ITEMS_O) mainTest.o -o game.out
	./game.out

#	---		MAIN 	---
mainTest.o : $(CHARACTERS_H) $(ITEMS_H) $(SCENE_H) mainTest.cpp
	$(CC) $(FLAGS) -c mainTest.cpp

#	---		ALL CHARACTER.o's 	---
Ape.o : Ape.cpp Ape.hpp Animal.hpp Character.hpp
	$(CC) $(FLAGS) -c Ape.cpp

Character.o : Character.cpp Character.hpp Item.hpp
	$(CC) $(FLAGS) -c Character.cpp

Crab.o : Crab.cpp Crab.hpp Animal.hpp Character.hpp
	$(CC) $(FLAGS) -c Crab.cpp

Merchant.o : Merchant.cpp Merchant.hpp Human.hpp Character.hpp
	$(CC) $(FLAGS) -c Merchant.cpp

Pirate.o : Pirate.cpp Pirate.hpp Human.hpp Character.hpp
	$(CC) $(FLAGS) -c Pirate.cpp

Player.o : Player.cpp Player.hpp Human.hpp Character.hpp
	$(CC) $(FLAGS) -c Player.cpp
#	---		ALL ITEM.o's 	---
Container.o : Container.cpp Container.hpp Item.hpp
	$(CC) $(FLAGS) -c Container.cpp

Weapon.o : Weapon.cpp Weapon.hpp Item.hpp
	$(CC) $(FLAGS) -c Weapon.cpp

Item.o : Item.cpp Item.hpp
	$(CC) $(FLAGS) -c Item.cpp

#	---		ALL SCENE.o's 	---
Beach.o : Beach.cpp Beach.hpp Outdoor.hpp
	$(CC) $(FLAGS) -c Beach.cpp

Cave.o : Cave.cpp Cave.hpp Scene.hpp
	$(CC) $(FLAGS) -c Cave.cpp

Indoor.o : Indoor.cpp Indoor.hpp Scene.hpp
	$(CC) $(FLAGS) -c Indoor.cpp

Jungle.o : Jungle.cpp Jungle.hpp Outdoor.hpp
	$(CC) $(FLAGS) -c Jungle.cpp

Outdoor.o : Outdoor.cpp Outdoor.hpp Scene.hpp
	$(CC) $(FLAGS) -c Outdoor.cpp

Room.o : Room.cpp Room.hpp Indoor.hpp
	$(CC) $(FLAGS) -c Room.cpp

Scene.o : Scene.cpp Scene.hpp Character.hpp Item.hpp
	$(CC) $(FLAGS) -c Scene.cpp
clean:
	\rm *.o *~ game.out
# all: mainTest.cpp
# 	clear
# 	g++ -g -std=c++11 -o main.out mainTest.cpp Crab.cpp Ape.cpp Merchant.cpp Pirate.cpp Player.cpp
# 	./main.out





CC = g++
FLAGS = -std=c++11 -g -Wall
CHARACTERS = Ape.cpp Character.cpp Crab.cpp Merchant.cpp Pirate.cpp Player.cpp 

character.out : $(CHARACTERS) mainTest.cpp
	$(CC) $(FLAGS) -o character.out $(CHARACTERS) mainTest.cpp

clean:
	rm -f *.out




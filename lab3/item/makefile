# all: mainItem.cpp
# 	clear
# 	g++ -g -std=c++11 -o main.out mainItem.cpp Container.cpp Weapon.cpp
# 	./main.out




CC = g++
FLAGS = -std=c++11 -g -Wall

item.out : Container.cpp mainItem.cpp Weapon.cpp Money.cpp
	$(CC) $(FLAGS) -o item.out Container.cpp mainItem.cpp Weapon.cpp Money.cpp

clean:
	rm -f *.out

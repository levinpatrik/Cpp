ITEM = ./item/



all: mainTest.cpp
	clear
	g++ -g -std=c++11 -o item.o $ITEMmainTest.cpp Crab.cpp Ape.cpp Merchant.cpp Pirate.cpp Player.cpp
	./main.out


g++ -g -std=c++11 -o main.out mainTest.cpp Crab.cpp Ape.cpp Merchant.cpp Pirate.cpp Player.cpp






# Here's a sample makefile for creating an executable called p1.
# OBJS = MovieList.o Movie.o NameList.o Name.o Iterator.o
# CC = g++
# DEBUG = -g
# CFLAGS = -Wall -c $(DEBUG)
# LFLAGS = -Wall $(DEBUG)

# g++ -g -std=c++11 -o main.out mainItem.cpp Container.cpp Weapon.cpp

# game.out : $(OBJS)
# 	$(CC) $(LFLAGS) $(OBJS) -o p1
	
# p1 : $(OBJS)
#     $(CC) $(LFLAGS) $(OBJS) -o p1

# MovieList.o : MovieList.h MovieList.cpp Movie.h NameList.h Name.h Iterator.h
#     $(CC) $(CFLAGS) MovieList.cpp

# Movie.o : Movie.h Movie.cpp NameList.h Name.h
#     $(CC) $(CFLAGS) Movie.cpp

# NameList.o : NameList.h NameList.cpp Name.h 
#     $(CC) $(CFLAGS) NameList.cpp

# Name.o : Name.h Name.cpp 
#     $(CC) $(CFLAGS) Name.cpp

# Iterator.o : Iterator.h Iterator.cpp MovieList.h
#     $(CC) $(CFLAGS) Iterator.cpp

# clean:
#     \rm *.o *~ p1

# tar:
#     tar cfv p1.tar Movie.h Movie.cpp Name.h Name.cpp NameList.h \
#             NameList.cpp  Iterator.cpp Iterator.h
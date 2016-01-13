# all: main.cpp
# 	clear
# 	g++ -g -std=c++11 -o main.out main.cpp Scene.cpp Beach.cpp Cave.cpp Jungle.cpp Indoor.cpp Outdoor.cpp Room.cpp
# 	./main.out

# all:main.cpp
# 	clear
# 	g++ -g -std=c++11 -o main.out main.cpp Scene.cpp Beach.cpp Cave.cpp Jungle.cpp Indoor.cpp Outdoor.cpp Room.cpp	
# 	valgrind --tool=memcheck --leak-check=yes ./main.out

CC = g++
FLAGS = -std=c++11 -g -Wall
SCENES =  Scene.cpp Indoor.cpp Outdoor.cpp Beach.cpp Cave.cpp Jungle.cpp Room.cpp 

scene.out : $(SCENES) main.cpp
	$(CC) $(FLAGS) -o scene.out  $(SCENES) main.cpp

clean:
	rm -f *.out
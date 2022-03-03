Battleship: main.o Executive.o AI.o Board.o
	g++ -std=c++11 -g -Wall main.o Executive.o AI.o Board.o -o Battleship

main.o: main.cpp Executive.h AI.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o:  Executive.cpp Executive.h Board.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

AI.o: AI.cpp AI.h Board.h
	g++ -std=c++11 -g -Wall -c AI.cpp

Board.o: Board.cpp Board.h
	g++ -std=c++11 -g -Wall -c Board.cpp

clean:
	rm *.o Battleship

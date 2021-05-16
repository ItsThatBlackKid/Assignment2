.default: all

all: qwirkle

clean:
	rm -rf qwirkle *.o *.dSYM

qwirkle: Tile.o Node.o LinkedList.o qwirkle.o GameBoard.o Menu.o Player.o TileBag.o QwirkleIO.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

test-linkedlist: Tile.o Node.o LinkedList.o testLinkedList.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

test-tilebag: Tile.o Node.o LinkedList.o TileBag.o testTileBag.o
	g++  -Wall -Werror -std=c++14 -g -O -o $@ $^


%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^

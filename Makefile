.default: all

all: qwirkle

clean:
	rm -rf qwirkle *.o *.dSYM

qwirkle: util.o Tile.o Node.o LinkedList.o  GameBoard.o Player.o TileBag.o  QwirkleIO.o Menu.o qwirkle.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

test-linkedlist: Tile.o Node.o LinkedList.o testLinkedList.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

test-tilebag: Tile.o Node.o LinkedList.o TileBag.o testTileBag.o
	g++  -Wall -Werror -std=c++14 -g -O -o $@ $^

test-tile: Tile.o testTile.o
	g++  -Wall -Werror -std=c++14 -g -O -o $@ $^


%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^

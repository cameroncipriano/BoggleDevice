CC = g++
CPPFLAGS = -Wall -Wextra -std=c++11
DEV = -g
OBJECTS = Tile.o Board.o Word.o GameDictionary.o BoggleGame.o
DEPS = Tile.h Board.h Word.h GameDictionary.h BoggleGame.h

vpath %.h headers
vpath %.cpp src

FindWords: main.o $(OBJECTS)
	$(CC) $(DEV) $(CPPFLAGS) -o $@ $^

FindWordsTest: TestMain.o $(OBJECTS)
	$(CC) $(DEV) $(CPPFLAGS) -o $@ $^

Board.o: Board.cpp Board.h Tile.h
	$(CC) $(DEV) $(CPPFLAGS) -c $<

BoggleGame.o: BoggleGame.cpp $(DEPS)
	$(CC) $(DEV) $(CPPFLAGS) -c $<

GameDictionary.o: GameDictionary.cpp GameDictionary.h
	$(CC) $(DEV) $(CPPFLAGS) -c $<

TestMain.o: TestMain.cpp $(DEPS)
	$(CC) $(DEV) $(CPPFLAGS) -c $<

Tile.o: Tile.cpp Tile.h
	$(CC) $(DEV) $(CPPFLAGS) -c $<

Word.o:: Word.cpp Word.h Tile.h
	$(CC) $(DEV) $(CPPFLAGS) -c $<

WordList.o: WordList.cpp WordList.h Word.h
	$(CC) $(DEV) $(CPPFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) FindWords FindWordsTest *.o
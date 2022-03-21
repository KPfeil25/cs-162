CC = g++ -std=c++11
exe_file = wumpus
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS := -DNDEBUG -03
endif

$(exe_file): bats.o gold.o wumpus.o driver.o pit.o event.o room.o player.o
	$(CC) bats.o gold.o wumpus.o driver.o pit.o event.o room.o player.o -o $(exe_file) $(CFLAGS)
bats.o: bats.cpp
	$(CC) -c bats.cpp $(CFLAGS)
gold.o: gold.cpp
	$(CC) -c gold.cpp $(CFLAGS)
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp $(CFLAGS)
driver.o: driver.cpp
	$(CC) -c driver.cpp $(CFLAGS)
pit.o: pit.cpp
	$(CC) -c pit.cpp $(CFLAGS)
event.o: event.cpp
	$(CC) -c event.cpp $(CFLAGS)
room.o: room.cpp
	$(CC) -c room.cpp $(CFLAGS)
player.o: player.cpp
	$(CC) -c player.cpp $(CFLAGS)
clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean

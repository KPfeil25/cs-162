CC = g++ -std=c++11
exe_file = list
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS := -DNDEBUG -03
endif

$(exe_file): driver.o node.o linked_list.o
	$(CC) driver.o node.o linked_list.o -o $(exe_file) $(CFLAGS)
driver.o: driver.cpp
	$(CC) -c driver.cpp $(CFLAGS)
node.o: node.cpp
	$(CC) -c node.cpp $(CFLAGS)
linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp $(CFLAGS)
clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
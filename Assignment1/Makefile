CC = g++ -std=c++11
exe_file = encyclopedia
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS := -DNDEBUG -03
endif

$(exe_file): encyclopedia.o driver.o
	$(CC) encyclopedia.o driver.o -o $(exe_file) $(CFLAGS)
encyclopedia.o: encyclopedia.cpp
	$(CC) -c encyclopedia.cpp $(CFLAGS)
driver.o: driver.cpp
	$(CC) -c driver.cpp $(CFLAGS)
clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean

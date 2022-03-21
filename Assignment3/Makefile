CC = g++ -std=c++11
exe_file = zoo
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS := -DNDEBUG -03
endif

$(exe_file): animal.o bear.o sea_lion.o tiger.o zoo.o functions.o driver.o
	$(CC) animal.o bear.o sea_lion.o tiger.o zoo.o functions.o driver.o -o $(exe_file) $(CFLAGS)
animal.o: animal.cpp
	$(CC) -c animal.cpp $(CFLAGS)
bear.o: bear.cpp
	$(CC) -c bear.cpp $(CFLAGS)
sea_lion.o: sea_lion.cpp
	$(CC) -c sea_lion.cpp $(CFLAGS)
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp $(CFLAGS)
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp $(CFLAGS)
functions.o: functions.cpp
	$(CC) -c functions.cpp $(CFLAGS)
driver.o: driver.cpp
	$(CC) -c driver.cpp $(CFLAGS)
clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
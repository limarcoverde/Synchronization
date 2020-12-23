CC = gcc

objects = sync_car.o testFile.o

sync_car: $(objects)
	$(CC) -pthread -o sync_car $(objects)

sync_car.o: sync_car.h

testFile.o: sync_car.h

.PHONY: clean
clean:
	rm $(objects) sync_car
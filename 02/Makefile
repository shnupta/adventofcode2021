CC = g++

all: calculate_depth aim

count_increases:
	$(CC) calculate_depth.cc -o calculate_depth

aim:
	$(CC) aim.cc -o aim

.PHONY: clean
clean:
	rm -rf *.o calculate_depth aim

CC = g++
CC_FLAGS = -std=c++17

all: power_consumption life_support

power_consumption:
	$(CC) $(CC_FLAGS) power_consumption.cc -o power_consumption

life_support:
	$(CC) $(CC_FLAGS) life_support.cc -o life_support

.PHONY: clean
clean:
	rm -rf *.o power_consumption life_support

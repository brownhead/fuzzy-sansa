COMPILE = g++
CFLAGS = -Wall -Werror

a.exe: main.o map_generation.o
	$(COMPILE) $(CFLAGS) main.o map_generation.o

main.o: main.cpp map_generation.hpp
	$(COMPILE) $(CFLAGS) -c main.cpp 

map_generation.o: map_generation.hpp map_generation.cpp
	$(COMPILE) $(CFLAGS) -c map_generation.cpp

clean:
	rm -f a.out *.exe
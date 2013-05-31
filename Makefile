COMPILE = g++
CFLAGS = -Wall -Werror

a.exe: main.o map_generation.o control.o Status.o geometric.o Item.o Monsters.o
	$(COMPILE) $(CFLAGS) main.o map_generation.o control.o Status.o geometric.o Item.o Monsters.o

main.o: main.cpp map_generation.o control.o Status.o geometric.o monsters.o Item.o
	$(COMPILE) $(CFLAGS) -c main.cpp 

map_generation.o: map_generation.hpp map_generation.cpp
	$(COMPILE) $(CFLAGS) -c map_generation.cpp

control.o: control.hpp control.cpp
	$(COMPILE) $(CFLAGS) -c control.cpp

Status.o: Status.cpp
	$(COMPILE) $(CFLAGS) -c Status.cpp

geometric.o: geometric.cpp geometric.hpp
	$(COMPILE) $(CFLAGS) -c geometric.cpp

monsters.o: monsters.cpp monsters.hpp geometric.cpp geometric.hpp
	$(COMPILE) $(FLAGS) -c monsters.cpp

Item.o: Item.hpp
	$(COMPILE) $(FLAGS) -c Item.cpp

clean:
	rm -f a.out *.exe

CC=g++
OBJ=c2.o
DEPS=main.hpp


main: main.o $(DEPS) $(OBJ)
	$(CC) -o main.out main.o $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system

c2.o: $(DEPS)
	$(CC) -c modules/c2.cpp -I /usr/include/

main.o: $(DEPS) $(OBJ)
	$(CC) -c main.cpp -I /usr/include/

clean:
	rm $(OBJ) main.o

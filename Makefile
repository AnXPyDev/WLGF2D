CC=g++
OBJ=c2.o game.o canvas.o draw.o engine.o config.o viewport.o actor.o background.o scene.o
DEPS=main.hpp


main: $(DEPS) $(OBJ) project/*.hpp
	$(CC) -o main.out project/*.cpp $(OBJ) -I /usr/include/ -lsfml-graphics -lsfml-window -lsfml-system 

c2.o: $(DEPS)
	$(CC) -c modules/c2.cpp -I /usr/include/

game.o: $(DEPS)
	$(CC) -c modules/game.cpp -I /usr/include/

engine.o: $(DEPS)
	$(CC) -c modules/engine.cpp -I /usr/include/

config.o: $(DEPS)
	$(CC) -c modules/config.cpp -I /usr/include/

viewport.o: $(DEPS)
	$(CC) -c modules/viewport.cpp -I /usr/include/

actor.o: $(DEPS)
	$(CC) -c modules/actor.cpp -I /usr/include/

background.o: $(DEPS)
	$(CC) -c modules/background.cpp -I /usr/include/

scene.o: $(DEPS)
	$(CC) -c modules/scene.cpp -I /usr/include/

draw.o: $(DEPS)
	$(CC) -c modules/draw.cpp -I /usr/include/

canvas.o: $(DEPS)
	$(CC) -c modules/canvas.cpp -I /usr/include/

clean:
	rm $(OBJ)

run:
	./main.out

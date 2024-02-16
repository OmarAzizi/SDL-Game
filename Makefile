CC = g++
INCLUDES = -I/usr/include/SDL2
LIBRARIES = -lSDL2 -lSDL2_image
CPP_FILES = $(wildcard *.cpp)
OBJECTS = Enemy.o Game.o main.o Player.o SDLGameObject.o TextureManager.o
EXECUTABLE = game

build: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LIBRARIES)

$(OBJECTS): %.o: %.cpp
	$(CC) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJECTS)


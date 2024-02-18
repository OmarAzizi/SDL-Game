CC = g++
INCLUDES = -I/usr/include/SDL2
LIBRARIES = -lSDL2 -lSDL2_image
SRC_DIR = src
BUILD_DIR = build
CPP_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPP_FILES))
EXECUTABLE = $(BUILD_DIR)/game

build: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LIBRARIES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

OBJS = **.cpp EntityComponentSystem/**.cpp

CC = g++
COMPILER_FLAGS = -w
PATHS= -I/usr/include/SDL2 
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2main

OBJ_NAME = GameEngine

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(PATHS) $(LINKER_FLAGS) -o $(OBJ_NAME)
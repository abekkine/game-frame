TARGET=gametest

SOURCES=main.cpp \
		Display.cpp \
		Game.cpp \
		Volume.cpp \
		PanZoom.cpp \
		Event.cpp \
		SampleLayer.cpp

OBJECTS=$(SOURCES:%.cpp=%.o)

FLAGS=-g -Wall -Wextra -Werror -Wfatal-errors `sdl-config --cflags`
CCLIBS=`sdl-config --libs` -lGL

all: $(OBJECTS)
	g++ $(FLAGS) -o $(TARGET) $(OBJECTS) $(CCLIBS)

.cpp.o:
	g++ $(FLAGS) -c -o $*.o $<

clean:
	$(RM) -rf $(TARGET) *.o *~  core*

memcheck: all
	valgrind ./$(TARGET)

memdetail: all
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --error-limit=no --suppressions=gf.supp ./$(TARGET)

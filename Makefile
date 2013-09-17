CXX = g++-4.7
SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_image -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -I/usr/local/include -Isrc
CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = popo_test

all: $(EXE)

$(EXE): main.o popo_core.o popo_graphics.o
	$(CXX) *.o $(LDFLAGS) -o $@

main.o: src/main.cc
	$(CXX) $(CXXFLAGS) $< -o $@

popo_core.o:
	$(CXX) $(CXXFLAGS) src/popo/core/*.cc

popo_graphics.o:
	$(CXX) $(CXXFLAGS) src/popo/graphics/*.cc

clean:
	rm *.o && rm $(EXE)
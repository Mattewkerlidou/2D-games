EXE = main.exe
SOURCES = src/Image.cpp src/main.cpp src/Moteur.cpp
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
CXXFLAGS = -Iinclude -ISDL2/include/SDL2 -g -Wall -Wformat
CXXFLAGS += -lSDL2 -lSDL2main -lSDL2_image -LSDL2/lib
CXXFLAGS += -lmingw32 -s

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:SLD2/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f $(EXE) $(OBJS)
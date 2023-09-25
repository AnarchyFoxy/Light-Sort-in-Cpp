CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = LightSort.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = light_switch

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = MiniWasalni
OBJS = main.o Graph.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

main.o: main.cpp Graph.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Graph.o: Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) -c Graph.cpp

clean:
	rm -f $(OBJS) $(TARGET)

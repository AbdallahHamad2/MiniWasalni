CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = MiniWasalni
SRCDIR = src
OBJS = main.o Graph.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

main.o: $(SRCDIR)/main.cpp $(SRCDIR)/Graph.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cpp -o main.o

Graph.o: $(SRCDIR)/Graph.cpp $(SRCDIR)/Graph.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Graph.cpp -o Graph.o

clean:
	rm -f $(OBJS) $(TARGET)

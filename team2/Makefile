OBJECTS = main.o dijkstra.o Graph.o EdgeNode.o inputData.o flo.o AppController.o AppView.o

CC = g++
CFLAGS = -c
TARGET =dij

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

clean: 
	rm -f $(OBJECTS) $(TARGET)

main.o: main.cpp AppController.h
dijkstra.o: dijkstra.cpp dijkstra.h
Graph.o: Graph.cpp Graph.h
EdgeNode.o: EdgeNode.cpp EdgeNode.h
inputData.o: inputData.cpp inputData.h Graph.h
flo.o : flo.cpp flo.h inputData.h
AppController.o : AppController.cpp AppController.h AppView.h dijkstra.h inputData.h flo.h
AppView.o : AppView.cpp AppView.h




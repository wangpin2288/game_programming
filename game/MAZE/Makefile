
demo		: mazeMap.o mazePerson.o demo.o
	g++ -o demo mazeMap.o mazePerson.o demo.o

demo.o		: demo.cpp
	g++ -o demo.o -c -g demo.cpp

mazeMap.o: mazeMap.cpp
	g++ -o mazeMap.o -c -g mazeMap.cpp

mazePerson.o: mazePerson.cpp
	g++ -o mazePerson.o -c -g mazePerson.cpp

clean:
	rm *.o
	rm demo

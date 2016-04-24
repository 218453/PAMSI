__start__: Program
	./Program 

Program: obj obj/Main.o obj/Array.o obj/List.o Graph.o
	g++ -o Program obj/Main.o obj/Array.o obj/List.o Graph.o

obj:
	mkdir obj

obj/Main.o: Main.cpp 
	g++ -c -o obj/Main.o Main.cpp

obj/Array.o: Array.cpp Array.hh
	g++ -c -o obj/Array.o Array.cpp

obj/List.o: List.cpp List.hh
	g++ -c -o obj/List.o List.cpp

obj/Graph.o: Graph.cpp Graph.hh
	g++ -c -o obj/Graph.o Graph.cpp

clean:
	rm -f obj/*.o Program

__start__: Program
	./Program 

Program: obj obj/Main.o obj/RBTree.o obj/RBTreeTest.o obj/TimeCounter.o
	g++ -o Program obj/Main.o obj/RBTree.o obj/RBTreeTest.o obj/TimeCounter.o

obj:
	mkdir obj

obj/Main.o: Main.cpp 
	g++ -c -o obj/Main.o Main.cpp

obj/RBTree.o: RBTree.cpp RBTree.hh
	g++ -c -o obj/RBTree.o RBTree.cpp

obj/RBTreeTest.o: RBTreeTest.cpp RBTreeTest.hh
	g++ -c -o obj/RBTreeTest.o RBTreeTest.cpp

obj/TimeCounter.o: TimeCounter.cpp TimeCounter.hh
	g++ -c -o obj/TimeCounter.o TimeCounter.cpp

clean:
	rm -f obj/*.o Program

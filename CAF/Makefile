CC = g++
CCOPT = -std=c++11 -g
LINKOPT = -L/usr/local/lib -lcaf_io -lcaf_core

# all: hello

# hello: hello.cpp hello.o
	# $(CC) $(CCOPT) -o hello hello.cpp $(LINKOPT)

hello: hello.o
	$(CC) $(CCOPT) -o hello hello.o $(LINKOPT)
	
hello.o: hello.cpp
	$(CC) $(CCOPT) -c hello.cpp

clean: 
	rm *.o hello
# build an executable named trashy from trashy.cpp
all: src/trashy.cpp
	g++ -g -Wall -o trashy src/options.cpp src/trashy.cpp 

 clean:
	 $(RM) trashy

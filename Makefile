# build an executable named trashy from trashy.cpp
all: src/trashy.cpp
	g++ --std=c++11 -g -Wall -o bin/trashy src/trashy.cpp src/options.cpp

 clean:
	 $(RM) trashy
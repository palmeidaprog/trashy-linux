# build an executable named trashy from trashy.cpp
all: src/trashy.cpp
	g++ --std=c++11 -g -Wall -o trashy src/options.cpp src/trashy.cpp 

 clean:
	 $(RM) trashy

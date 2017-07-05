# build an executable named trashy from trashy.cpp
all: src/trashy.cpp
	g++ --std=c++14 -g -Wall -o bin/trashy src/output.cpp src/options.cpp src/devices.cpp src/trashy.cpp
 clean:
	 $(RM) trashy

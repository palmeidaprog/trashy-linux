/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#include <iostream>
#include <vector>
#include <string>
#include "options.h"
#include "error.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

void error_msg(const Error e); // prints error msgs

int main(int argc, char *argv[]) {
	
	// convert C String to std::string
	vector<string> args;
	for(int i = 1; i < argc; ++i) {
		args.push_back(argv[i]);
	}

	if(argc == 1) {
		error_msg(Error::NO_ARGS);
	}
	Options op;


	
	return 0;
}

// prints error msgs
void error_msg(const Error e) {
	switch(e) {
		case Error::NO_ARGS:
			cout << "trashy needs commands or arguments." << endl;
			cout << "Usage: " << "trashy -[options] [command] " <<
			"arguments" << endl; 
			cout << "Try 'trashy --help' or 'trashy -h' for more " <<
			"information" << endl;
			break;
	}
}
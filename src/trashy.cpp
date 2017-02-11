/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

/*
* main() return errors
* 1 = no arguments
*/

#define VERSION "v0.1 alpha"
#define AUTHOR "Paulo R. Almeida Filho"
#define MAIL "<palmeidaprogramming@gmail.com>"
#define SITE "http://www.github.com/palmeidaprog/"

#include <iostream>
#include <vector>
#include <string>
#include "options.h"
#include "output_msg.h"

using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;

void output_msg(const Output_msg o); // prints error msgs

int main(int argc, char *argv[]) {
	
	// convert C String to std::string
	vector<string> args;
	for(int i = 1; i < argc; ++i) {
		args.push_back(argv[i]);
	}

	// no arguments/commands/options
	if(argc <= 1) {
		output_msg(Output_msg::NO_ARGS);
	}
	// show help menu
	else if(string(argv[1]) == "-h" || string(argv[1] == "--help")) {
		output_msg(Output_msg::HELP);
	}
	else{ 

	}

	Options op;
	
	return 0;
}

//--Functions and procedures-----------------------------------------------------

// prints output and error msgs
void output_msg(const Output_msg o) {
	switch(o) {
		case Output_msg::NO_ARGS:
			cerr << "trashy: needs commands or arguments." << endl;
			cerr << "Usage: " << "trashy -[OPTION] ... [COMMAND] " <<
			"... arguments\n" << endl; 
			cerr << "Try 'trashy --help' or 'trashy -h' for more " <<
			"information" << endl;
			break;
		case Output_msg::HELP:
			cout << "Trashy " << VERSION <<", a trash (delete) manager" 
				<< "for terminal." << endl;
			cout << AUTHOR << " " << MAIL << endl;
			cout << SITE << endl << endl;
			break;
	}
}
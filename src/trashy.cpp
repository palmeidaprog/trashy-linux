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

#include <vector>
#include <string>
#include "options.h"
#include "output_msg.h"
#include "output.h"

using std::string;
using std::vector;
using trashy::output::Options;
using trashy::output::OutputMsg;
using trashy::output::output_msg; // function

int main(int argc, char *argv[]) {
	Options op;
	
	// convert C String to std::string
	vector<string> args;
	for(int i = 1; i < argc; ++i) {
		args.push_back(string(argv[i]));
	}

	// no arguments/commands/options
	if(argc <= 1) {
		output_msg(OutputMsg::NO_ARGS);
	}
	// show help menu
	else if(string(argv[1]) == "-h" || string(argv[1]) == "--help") {
<<<<<<< HEAD
		output_msg(OutputMsg::HELP);
	}
	else{ 
		
=======
		output_msg(Output_msg::HELP);
	}
	else{ 
		output_msg(op.parse_options(args));
>>>>>>> origin/sync
	}

	return 0;
}
<<<<<<< HEAD
=======

//--Functions and procedures-----------------------------------------------------

// prints output and error msgs
void output_msg(const Output_msg o) {
	switch(o) { // todo: To add cases for other Output_msg values
		case Output_msg::NO_ARGS:
			cerr << "trashy: needs commands or arguments." << endl;
			cerr << "Usage: " << "trashy -[OPTION] ... [COMMAND] " <<
			"... arguments\n" << endl; 
			cerr << "Try 'trashy --help' or 'trashy -h' for more " <<
			"information" << endl;
			break;
		case Output_msg::HELP:
			cout << "Trashy " << VERSION <<", a trash (delete) manager" 
				<< " for terminal." << endl;
			cout << AUTHOR << " " << MAIL << endl;
			cout << SITE << endl << endl;
			break;
		default:
			break;
	}
}
>>>>>>> origin/sync

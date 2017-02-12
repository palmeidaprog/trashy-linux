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
	
	// convert C String to std::string
	vector<string> args;
	for(int i = 1; i < argc; ++i) {
		args.push_back(argv[i]);
	}

	// no arguments/commands/options
	if(argc <= 1) {
		output_msg(OutputMsg::NO_ARGS);
	}
	// show help menu
	else if(string(argv[1]) == "-h" || string(argv[1]) == "--help") {
		output_msg(OutputMsg::HELP);
	}
	else{ 

	}

	Options op;
	
	return 0;
}

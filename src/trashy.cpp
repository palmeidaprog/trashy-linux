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
#include "devices.h"

using std::string;
using std::vector;
using trashy::output::Options;
using trashy::output::OumtputMsg;
using trashy::output::output_msg; // function
using trashy::config::Devices;

int main(int argc, char *argv[]) {
	Devices devices;
	Options op(devices);
	
	// convert C String to std::string
	vector<string> args;
	for(int i = 1; i < argc; ++i) {
		args.push_back(string(argv[i]));
	}

	// no arguments/commands/options
	if(argc <= 1) {
		output_msg(OutputMsg::NO_ARGS);
	}
	else{
		output_msg(op.parse_args(args));
	}

	return 0;
}


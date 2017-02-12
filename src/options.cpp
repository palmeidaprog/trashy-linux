/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

// class header
#include "options.h"

// set and getters
const bool &Options::is_quiet() {
	return quiet;
}

void Options::set_quiet(const bool &q) {
	quiet = q;
}

const bool &Options::is_verbose() {
	return verbose;
}

void Options::set_verbose(const bool &verb) {
	verbose = verb;
}

// read the args for options
const Output_msg parse_options(const vector<string> &args) {
	return Output_msg::NO_ARGS;
}
/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#ifndef OPTIONS_H
#define OPTIONS_H

#include <vector>
#include <string>
#include "output_msg.h"

using std::string;
using std::vector;

class Options {

	bool quiet, verbose;

public:
	Options(): quiet(true), verbose(true) {	} 
	
	// setters and getters
	const bool &is_quiet();
	void set_quiet(const bool &q);
	const bool &is_verbose();
	void set_verbose(const bool &verb);

	// read and parse the args for options
	const Output_msg parse_options(const vector<string> &args);
};

#endif
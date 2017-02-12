/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#define VERSION "v0.1 alpha"
#define AUTHOR "Paulo R. Almeida Filho"
#define MAIL "<palmeidaprogramming@gmail.com>"
#define SITE "http://www.github.com/palmeidaprog/"

#include <iostream>
#include "output_msg.h"
#include "output.h"

using std::cerr;
using std::cout;
using std::endl;
using trashy::output::OutputMsg;

namespace trashy { namespace output {

	// prints program output
	void output_msg(const OutputMsg o) {
		switch(o) {
			case OutputMsg::NO_ARGS:
				cerr << "trashy: needs commands or arguments." << endl;
				cerr << "Usage: " << "trashy -[OPTION] ... [COMMAND] " <<
				"... arguments\n" << endl; 
				cerr << "Try 'trashy --help' or 'trashy -h' for more " <<
				"information" << endl;
				break;
			case OutputMsg::HELP:
				cout << "Trashy " << VERSION <<", a trash (delete) manager" 
					<< "for terminal." << endl;
				cout << AUTHOR << " " << MAIL << endl;
				cout << SITE << endl << endl;
				break;
			default:
				break;
		}
	}
}}
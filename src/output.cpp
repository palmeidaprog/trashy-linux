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
#include <string>
#include "output_msg.h"
#include "output.h"

using std::cerr;
using std::cout;
using std::endl;
using trashy::output::OutputMsg;

namespace trashy { namespace output {

	// help menu
	void help() {
		cout << "Trashy " << VERSION <<", a trash (delete) manager" 
					<< "for terminal." << endl;
		cout << AUTHOR << " " << MAIL << endl;
		cout << SITE << endl << endl;
	}

	void no_args() {
		cerr << "trashy: needs commands or arguments." << endl;
		cerr << "Usage: " << "trashy -[OPTION] ... [COMMAND] " <<
				"... arguments\n" << endl; 
		cerr << "Try 'trashy --help' or 'trashy -h' for more " <<
				"information" << endl;
	}

	void about() {
		cout << "Trashy " << VERSION <<", a trash (delete) manager" 
					<< "for terminal." << endl;
		cout << AUTHOR << " " << MAIL << endl;
		cout << SITE << endl << endl;
	}

	void invalid_args(w) {
		cerr << "INVALID_OPTION" << endl;
	}

	// prints program output
	void output_msg(const OutputMsg o) {
		switch(o) {
			case OutputMsg::NO_ARGS:
				no_args();				
				break;
			case OutputMsg::HELP:
				help();
				break;
			case OutputMsg::ABOUT:
				about();
				break;
			case OutputMsg::SUCCESS:
				cout << "Success!" << endl;
				break;
			case OutputMsg::INVALID_OPTION:
				invalid_args();
				break;
			default:
				cout << "default" << endl;
				break;
		}
	}
}}
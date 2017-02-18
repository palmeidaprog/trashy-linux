/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#include <vector>
#include <string>
#include "output_msg.h"
#include "options.h"

using std::vector;
using std::string;
using trashy::output::OutputMsg;

namespace trashy { namespace output {

	const bool &Options::is_quiet() {
		return quiet;
	}

	void Options::set_quiet(const bool &q) {
		if(q) {
			verbose = false;
		}
		quiet = q;
	}

	const bool &Options::is_verbose() {
		return verbose;
	}

	void Options::set_verbose(const bool &verb) {
		if(verb) {
			quiet = false;
		}
		verbose = verb;
	}

	// parse arguments todo: finish
	const OutputMsg Options::parse_args(const vector<string> &args) {
		for(string s : args) {
			bool search_for_options = true;

			// search for options until finds a -- 
			if(search_for_options) {
				// "--" disable options
				if(s == "--") { 
					search_for_options = false;
				}
				// read options
				else if(s[0] == '-') { 
					// single - options
					if(s[1] != '-') {
						OutputMsg out = read_options(s);
						if(out != OutputMsg::SUCCESS) {
							return out;
						}
					}
					// double -- (verbose) options
					else {
						OutputMsg out = read_verbose_options(s);
						if(out != OutputMsg::SUCCESS) {
							return out;
						}
					}			
				}
				else { // files to delete 
					files_to_trash.emplace_back(s);
				} 
			}
			else { // files to delete
				files_to_trash.emplace_back(s);
			}
		}

		return OutputMsg::SUCCESS;
	}

	const OutputMsg Options::read_verbose_options(const string &str) {
		return OutputMsg::INVALID_OPTION;
	}

	const OutputMsg Options::read_options(const string &str) {
		for(char c : str) {
			if(c != '-') {
				switch(c) {
					case 'v':
						set_verbose(true);
						break;
					case 'q':
						set_quiet(true);
						break;
					case 'V':
						return OutputMsg::ABOUT;
						break;
					case 'h':
						return OutputMsg::HELP;
						break;
					default:
						return OutputMsg::INVALID_OPTION;
						break;
				}
			}
		}
		return OutputMsg::SUCCESS;
	}
}}


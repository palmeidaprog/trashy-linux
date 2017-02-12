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
		quiet = q;
	}

	const bool &Options::is_verbose() {
		return verbose;
	}

	void Options::set_verbose(const bool &verb) {
		verbose = verb;
	}

	// parse arguments todo: finish
	const OutputMsg &parse_args(const vector<string> &args) {
		for(string s : args) {
			// "--" disable options
			if(s == "--") { 
				break; 
			}
			else if(s[0] == "-" && s[0]) {
				for()
			}
		}

		return OutputMsg::INVALID_OPTION;
	}
}}


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
			bool search_for_options = true;

			// search for options until finds a -- 
			if(search_for_options) {
				// "--" disable options
				if(s == "--") { 
					search_for_options = false;
				}
				else if(s[0] == "-") { // option
					if(s[1] != "-") {
						read_options(s);
					}
					else {
						read_verbose_options(s);
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
	}

	


}}


/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#ifndef OPTIONS_H
#define OPTIONS_H

<<<<<<< HEAD
using std::vector;
using std::string;
using trashy::output::OutputMsg;
=======
#include <vector>
#include <string>
#include "output_msg.h"

using std::string;
using std::vector;

class Options {
>>>>>>> origin/sync

namespace trashy { namespace output {
	class Options {
		bool quiet, verbose;
		vector<string> 

<<<<<<< HEAD
	public:
		Options(): quiet(false), verbose(false) {	} 
=======
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
>>>>>>> origin/sync

		const bool &is_quiet();
		void set_quiet(const bool &q);
		const bool &is_verbose();
		void set_verbose(const bool &verb);

		// parse arguments
		const OutputMsg &parse_args(const vector<string> &args);
	};
}}

#endif // OPTIONS_H
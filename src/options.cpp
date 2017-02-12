/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#include "options.h"

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
}}

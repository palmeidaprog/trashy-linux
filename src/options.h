/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#ifndef OPTIONS_H
#define OPTIONS_H

using std::vector;
using std::string;
using trashy::output::OutputMsg;

namespace trashy { namespace output {
	class Options {
		bool quiet, verbose;
		vector<string> 

	public:
		Options(): quiet(false), verbose(false) {	} 

		const bool &is_quiet();
		void set_quiet(const bool &q);
		const bool &is_verbose();
		void set_verbose(const bool &verb);

		// parse arguments
		const OutputMsg &parse_args(const vector<string> &args);
	};
}}

#endif // OPTIONS_H
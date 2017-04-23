/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#ifndef OPTIONS_H
#define OPTIONS_H

#include "output_msg.h"
#include "devices.h"

using std::vector;
using std::string;
using trashy::output::OutputMsg;
using trashy::config::Devices;

namespace trashy { namespace output {
	class Options {
		bool quiet, verbose, confirmation;
		vector<string> files_to_trash;
		const string PWD_FILE = "/.trashy/pwd_file";
		Devices devices;

		public:
			Options(Devices &dev): quiet(false), verbose(false), 
					confirmation(false), devices(dev) {	} 

		// setters and getters
		const bool &is_quiet();
		void set_quiet(const bool &q);
		const bool &is_verbose();
		void set_verbose(const bool &verb);
		const bool &is_confirmation();
		void set_confirmation(const bool &conf);

		// parse arguments
		const OutputMsg parse_args(const vector<string> &args);
		const OutputMsg read_verbose_options(const string &str); 
		const OutputMsg read_options(const string &str);
		void move_to_trash(const string &to_delete);
		const string get_trash_bin(const string &path_to_parse);
		void print_trash_files();
	};
}}

#endif // OPTIONS_H
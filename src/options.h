/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#ifndef OPTIONS_H
#define OPTIONS_H

class Options {

	bool quiet, verbose;

public:
	Options(): quiet(true), verbose(true) {	} 
	const bool &is_quiet();
	void set_quiet(const bool &q);
	const bool &is_verbose();
	void set_verbose(const bool &verb);
};

#endif
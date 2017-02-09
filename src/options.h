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

	static bool quiet, verbose;
	Options() {	} // private so defeats instanciaton

public:
	static const bool &is_quiet();
	static void set_quiet(const bool &q);
	static const int &is_verbose();
	static void set_verbose(const bool &verb);
};

#endif
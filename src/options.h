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
public:
	Options(): quiet(false), verbose(false) { }

private:
	static bool quiet, verbose;

public:
	
	static const bool &is_quiet() const;
	static void set_quiet(const bool &q);
	static const int &is_verbose() const;
	static void set_verbose(const bool &q);
};

#endif
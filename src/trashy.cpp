/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#include <iostream>
#include <vector>
#include <string>
#include "options.h"

int main(int argc, char *argv[]) {
	//std::vector<string> args(argv);

	Options::set_quiet(true);
	Options::set_verbose(true);
	std::cout << "Quiet: " << Options::is_quiet() << " " << Options::is_verbose;
	return 0;
}
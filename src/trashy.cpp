/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#include <iostream>
//#include "options.h"
#include "options.h"

int main(int argc, char *argv[]) {
	//std::vector<string> args(argv);
	Options op;

	op.set_quiet(true);
	op.set_verbose(true);
	std::cout << "Quiet: " << op.is_quiet() << " " << op.is_verbose();
	
	return 0;
}
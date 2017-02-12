/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#ifndef OUTPUT_MSG_H
#define OUTPUT_MSG_H

namespace trashy { namespace output {

	// to be used with trashy::output::output_msg()
	// and options class
	enum class OutputMsg { 
		NO_ARGS, HELP, INVALID_OPTION
	};

}}

#endif // OUTPUT_MSG_H

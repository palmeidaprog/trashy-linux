/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#ifndef OUTPUT_H
#define OUTPUT_H

using trashy::output::OutputMsg;

namespace trashy { namespace output {

	void output_msg(const OutputMsg o); // prints program output
}}

#endif // OUTPUT_H
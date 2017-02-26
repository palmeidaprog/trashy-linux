/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#ifndef DEVICES_H
#define DEVICES_H

using std::vector;
using std::string;

namespace trashy { namespace config {
	const static string REM_LIST = "~/.trashy/remlist";
	const static string DEV_LIST = "~/.trashy/devlist";

	class Devices {
	vector<string> dev_roots; // devices root paths

	public:
		Devices() {
			get_devices();
		}

	private:
		void get_devices();
	};



}} // trashy::config


#endif // DEVICES_H
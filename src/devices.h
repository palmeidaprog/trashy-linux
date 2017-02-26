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

	class Devices {
		vector<string> dev_roots; // devices root paths
		const string REM_LIST = "/.trashy/remlist";
		const string DEV_LIST = "/.trashy/devlist";
		string usrhome;


	public:
		Devices() {
			get_devices();
		}

	private:
		void get_devices();
		string get_home_dir();
	};



}} // trashy::config


#endif // DEVICES_H
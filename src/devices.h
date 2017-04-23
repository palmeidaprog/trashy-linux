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
		const string REM_LIST2 = "/.trashy/remlist2";
		const string DEV_LIST = "/.trashy/devlist";
		string usrhome;
		string os;

		enum class DeviceType {
			LOCAL, CIFS, SSH_MOUNT
		};

	public:
		Devices() {
			update_devices();
		}

		string get_home_dir();
		string get_os_name();
		void print_devices();

	private:
		void update_devices();
		void find_device(const string &file);
		void create_trash();
	};	

}} // trashy::config


#endif // DEVICES_H
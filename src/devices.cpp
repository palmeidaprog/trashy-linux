/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#include <vector>
#include <string>
#include <fstream>
#include <iostream> //test
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "devices.h"

using std::vector;
using std::string;
using std::ifstream;
using std::getline;
using std::cout;

namespace trashy { namespace config {

	void Devices::update_devices() {
		usrhome = get_home_dir();
		system("mkdir -p ~/.trashy"); // creates program folder
		system("rm -f ~/.trashy/devlist");
		system("rm -f ~/.trashy/remlist");

		string os_name(get_os_name());

		if(os_name == "Mac OSX") {
			system("mount | grep -i /dev/di | cat >~/.trashy/devlist"); 
			system("mount | grep -i // | cat >~/.trashy/remlist");
			system("mount | grep -i :/ | cat >~/.trashy/remlist2");
			cout << "mac\n"; // test
		}
		else {
			system("mount -l | grep -i /dev/s | grep -v tmpfs | cat >~/.trashy/devlist"); 
			system("mount -l | grep -i // | cat >~/.trashy/remlist");
			system("mount -l | grep -i :/ | cat >~/.trashy/remlist2");
		}
			
		find_device(usrhome + DEV_LIST);
		find_device(usrhome + REM_LIST);
		find_device(usrhome + REM_LIST2);
		create_trash();
	}

	string Devices::get_home_dir() {
		const char *homedir;

		if ((homedir = getenv("HOME")) == NULL) {
			struct passwd *pw = getpwuid(getuid());
		    homedir = pw->pw_dir;
		}

		return string(homedir);
	}

	string Devices::get_os_name() {
	    #ifdef _WIN32
	    return "Windows 32-bits";
	    #elif _WIN64
	    return "Windows 64-bits";
	    #elif __unix || __unix__
	    return "Unix";
	    #elif __APPLE__ || __MACH__
	    return "Mac OSX";
	    #elif __linux__
	    return "Linux";
	    #elif __FreeBSD__
	    return "FreeBSD";
	    #else
	    return "Other";
	    #endif
	}                      

	void Devices::find_device(const string &file) {
		ifstream fileInput(file);

		if(fileInput) {
			string line, device_path = "";

			while(getline(fileInput, line)) {
				if(os == "Mac OSX") {
					for(unsigned i = line.find("on /") + 3; i < line.find(" (osxfuse"); ++i) {
						device_path += line.at(i);
					}
				}
				else {
					for(unsigned i = line.find("on /") + 3; i < line.find(" type"); ++i) {
						device_path += line.at(i);
					}	
				}
				dev_roots.emplace_back(device_path);
				device_path = "";
			} // todo: create DeviceRoot class
		}
		fileInput.close();
	}

	void Devices::create_trash() {
		for(string s : dev_roots) {
			if(s == "/") {
				system(string("mkdir -p " + usrhome + "/.Trash").c_str());
			}
			else {
				system(string("mkdir -p " + s + "/.Trash").c_str());	
			}
		}
	}

}} // trashy::config
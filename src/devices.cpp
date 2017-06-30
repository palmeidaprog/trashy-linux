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
#include <iostream> 
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "devices.h"

using std::vector;
using std::string;
using std::ifstream;
using std::getline;
using std::endl;
using std::exception;
using std::cout;
using std::endl;

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
		}
		else {
			string cmd("mount -l | grep -i /dev/s | grep -v tmpfs | cat ");
			cmd += ">~/.trashy/devlist";
			system(cmd.c_str()); 
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

		try {
			if(fileInput) {
				string line, device_path = "";

				while(getline(fileInput, line)) {
					if(get_os_name() == "Mac OSX") {
						auto lin_max = line.find(" (hfs");
						for(unsigned i = line.find("on /") + 3; i < lin_max; 
							++i) {
							device_path += line.at(i);
						}
					}
					else {
						auto line_max = line.find(" type");
						for(unsigned i = line.find("on /") + 3; i < line_max;
							 ++i) {
							device_path += line.at(i);
						}	
					}
					dev_roots.emplace_back(device_path);
					device_path = "";
				} // todo: create DeviceRoot class
			}
		}
		catch(std::out_of_range& e) {
			std::cerr << "ERROR FINDING STORAGE DEVICES" << endl;
		}
		catch(exception& e) {
			std::cerr << "Exception: " << e.what() << endl;
		}
		fileInput.close();
	}

	void Devices::print_devices() { // TODO: improve appearance
		unsigned i = 1;

		cout << "Devices:" << endl;
		for(string s: dev_roots) {
			cout << i++ << ": " << s << endl; 
		}
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
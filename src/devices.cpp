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

namespace trashy { namespace config {

	void Devices::get_devices() {
		usrhome = get_home_dir();
		system("mkdir -p ~/.trashy"); // creates program folder
		system("rm -f ~/.trashy/devlist");
		system("rm -f ~/.trashy/remlist");
		system("mount -l | grep -i /dev/s | grep -v tmpfs | cat >~/.trashy/devlist"); 
		system("mount -l | grep -i // | cat >~/.trashy/remlist");

		ifstream fileInput(usrhome+DEV_LIST);

		if(fileInput) {
			string line;

			while(getline(fileInput, line)) {
				// std::cout << line << std::endl; // test line
			}

			fileInput.close();
		}
	}

	string Devices::get_home_dir() {
		const char *homedir;

		if ((homedir = getenv("HOME")) == NULL) {
			struct passwd *pw = getpwuid(getuid());
		    homedir = pw->pw_dir;
		}

		return string(homedir);
	}

}} // trashy::config
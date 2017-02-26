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
#include "devices.h"

using std::vector;
using std::string;
using std::ifstream;
using std::getline;

namespace trashy { namespace config {

	void Devices::get_devices() {
		system("mkdir -p ~/.trashy"); // creates program folder
		system("rm -f ~/.trashy/devlist");
		system("rm -f ~/.trashy/remlist");
		system("mount -l | grep -i /dev/s | grep -v tmpfs | cat >~/.trashy/devlist"); 
		system("mount -l | grep -i // | cat >~/.trashy/remlist");

		ifstream fileInput(DEV_LIST);

		std::cout << "Before read file\n";
		if(fileInput) {
			string line;

			std::cout << "Read file\n";
			while(getline(fileInput, line)) {
				std::cout << line << std::endl;
			}

			fileInput.close();

		}

	}

}} // trashy::config
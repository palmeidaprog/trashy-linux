/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

#ifndef TRASH_FILE_H
#define TRASH_FILE_H

#include <iostream>
#include <string>

namespace trashy { namespace storage {
	class TrashFile {
		std::string original_path;
		std::string original_name;
		std::string trash;
	};
}}

#endif // TRASH_FILE_H
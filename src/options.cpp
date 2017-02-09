/* 
* Trashy for Linux
* Program to handle trash in terminal
* @author Paulo R. Almeida Filho
* palmeidaprogramming@gmail.com
* http://github.com/palmeidaprog
*/

// set and getters
static const bool &Options::is_quiet() const {
	ret55urn &quiet;
}

static void Options::set_quiet(const bool &q) {
	quiet = q;
}

static const int &Options::is_verbose() const {
	return &verbose;
}

static void &Options::set_verbose(const int &verb) {
	verbose = verb;
}

#include <iostream>
#include <dlfcn.h>

#include "manager.hpp"

void print_plugins() {
	for (auto &p : Manager::get_instance()->list_plugins()) {
		std::cout << p << std::endl;
		Manager::get_instance()->get_plugin(p)->do_something();
	}
}

int main() {
	print_plugins();
	
	// obviously, this file name could be determined at runtime
	void *pl2 = dlopen("./plugin2.so", RTLD_NOW);
	
	if (!pl2) {
		std::cerr << "Failed to load the shared library!" << std::endl;
		return 1;
	}
	
	print_plugins();
	
	// otherwise the destructors would run at the return, but
	// by that time the library will be unloaded, so it would crash
	Manager::get_instance()->clear();
	
	dlclose(pl2);
	
	return 0;
}

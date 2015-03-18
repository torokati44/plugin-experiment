#include "plugin1.hpp"

#include <iostream>

#include "manager.hpp"

REGISTER_PLUGIN(Plugin1)

void Plugin1::do_something() {
	std::cout << "Hi! I'm Plugin1!" << std::endl;
}

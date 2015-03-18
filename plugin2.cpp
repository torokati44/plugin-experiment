#include "plugin2.hpp"

#include <iostream>

#include "manager.hpp"

REGISTER_PLUGIN(Plugin2)

void Plugin2::do_something() {
	std::cout << "Hi! I'm Plugin2!" << std::endl;
}

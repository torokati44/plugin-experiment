#include "manager.hpp"
#include <algorithm>
#include <stdexcept>

std::shared_ptr<Plugin> Handle::create_instance() {
	throw std::runtime_error("Not implemented!");
}

std::string Handle::get_name() {
	throw std::runtime_error("Not implemented!");
}

std::shared_ptr<Manager> Manager::inst = nullptr;

std::shared_ptr<Manager> Manager::get_instance() {
	if (!inst) {
		inst = std::make_shared<Manager>();
	}
	return inst;
}

void Manager::clear() {
	plugins.clear();
}

void Manager::register_plugin(std::shared_ptr<Handle> h) {
	plugins.push_back(h);
}

std::vector<std::string> Manager::list_plugins() {
	std::vector<std::string> names;
	for (auto &h : plugins) {
		names.push_back(h->get_name());
	}
	return names;
}

std::shared_ptr<Plugin> Manager::get_plugin(std::string name) {
	for (auto h : plugins) {
		if (h->get_name() == name) {
			return std::shared_ptr<Plugin>(h->create_instance());
		}
	}
	return nullptr;
}

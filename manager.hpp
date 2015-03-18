#ifndef MANAGER_HPP_INCLUDED
#define MANAGER_HPP_INCLUDED

#include <vector>
#include <string>
#include <memory>

#include "plugin.hpp"


#define REGISTER_PLUGIN(NAME) \
	class NAME ## _Handle : public Handle { \
	public: \
		virtual std::shared_ptr<Plugin> create_instance() { return std::make_shared<NAME>(); } \
		virtual std::string get_name() { return std::string(#NAME); } \
	}; \
	 \
	class NAME ## _Registrator { \
	public: \
		NAME ## _Registrator() { Manager::get_instance()->register_plugin(std::make_shared<NAME ## _Handle>()); } \
	}; \
	 \
	static NAME ## _Registrator NAME ## _reg;


class Handle {
public:
	virtual std::shared_ptr<Plugin> create_instance();
	virtual std::string get_name();
};


class Manager {
	std::vector<std::shared_ptr<Handle>> plugins;
	static std::shared_ptr<Manager> inst;
	
public:
	static std::shared_ptr<Manager> get_instance();
	
	void clear();
	void register_plugin(std::shared_ptr<Handle> h);
	std::vector<std::string> list_plugins();
	std::shared_ptr<Plugin> get_plugin(std::string name);
};

#endif // MANAGER_HPP_INCLUDED

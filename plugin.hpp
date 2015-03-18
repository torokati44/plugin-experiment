#ifndef PLUGIN_HPP_INCLUDED
#define PLUGIN_HPP_INCLUDED

class Plugin {
public:
	virtual void do_something() = 0;
	virtual ~Plugin() { };
};

#endif // PLUGIN_HPP_INCLUDED


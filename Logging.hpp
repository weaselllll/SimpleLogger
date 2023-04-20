#pragma once

#include <iostream>
#include <sstream>


class Logger
{
private:
	bool m_is_logging_enable;

public:
	typedef enum {
		DEBUG,
		INFO,
		WARN,
		ERROR,
		CRIT
	} LogType;


	Logger();

	void say(LogType type, std::string text);

	void disable();
	void enable();
	void toggle();
};


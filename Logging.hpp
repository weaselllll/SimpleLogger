#pragma once

#include <iostream>
#include <sstream>

#define LOGTYPE Logger::LogType

class Logger
{
private:
	bool m_is_logging_enable;
	std::string m_source;

public:
	typedef enum {
		DEBUG,
		INFO,
		WARN,
		ERROR,
		CRIT
	} LogType;


	Logger(std::string source);

	void say(LogType type, std::string text);

	void disable();
	void enable();
	void toggle();
};
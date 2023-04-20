#include "Logging.hpp"


Logger::Logger()
{
	m_is_logging_enable = true;
}

void Logger::say(LogType type, std::string text)
{
	if (!m_is_logging_enable) return;

	std::stringstream buffer;
		
	// check type
	switch (type)
	{
	case DEBUG:
		buffer << "\x1B[97m[Debug]";
		break;
	case INFO:
		buffer << "\x1B[92m[Info]";
		break;
	case WARN:
		buffer << "\x1B[33m[Warning]";
		break;
	case ERROR:
		buffer << "\x1B[31m[Error]";
		break;
	case CRIT:
		buffer << "\x1B[41m[Critical]";
		break;
	default:
		buffer << "\x1B[90m[UNDEF]";
		break;
	}

	buffer << ": " << text;
	buffer << "\033[0m";

	std::cout << buffer.str() << '\n';
}

void Logger::disable()
{
	m_is_logging_enable = false;
}

void Logger::enable()
{
	m_is_logging_enable = true;
}

void Logger::toggle()
{
	m_is_logging_enable = !m_is_logging_enable;
}

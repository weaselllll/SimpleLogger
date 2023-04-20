#include "Logging.hpp"


Logger::Logger(std::string source)
{
	m_source = source;
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
		buffer << "\x1B[97m(" << m_source << "):[Debug]";
		break;
	case INFO:
		buffer << "\x1B[92m(" << m_source << "):[Info]";
		break;
	case WARN:
		buffer << "\x1B[33m(" << m_source << "):[Warning]";
		break;
	case ERROR:
		buffer << "\x1B[31m(" << m_source << "):[Error]";
		break;
	case CRIT:
		buffer << "\x1B[41m(" << m_source << "):[Critical]";
		break;
	default:
		buffer << "\x1B[90m(" << m_source << "):[UNDEF]";
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

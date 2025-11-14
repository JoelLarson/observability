#include "LogEntry.h"

LogEntry::LogEntry(std::string message)
    : m_message(std::move(message))
{
    // empty
}

LogEntry::LogEntry(std::string timestamp, std::string message)
    : m_timestamp(std::move(timestamp)),
      m_message(std::move(message))
{
    // empty
}

const std::string& LogEntry::message() const
{
    return m_message;
}

const std::string& LogEntry::timestamp() const
{
    return m_timestamp;
}

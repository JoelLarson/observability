#include "LogEntry.h"

LogEntry::LogEntry(std::string raw_data)
    : m_raw_data(std::move(raw_data))
{
    // empty
}

const std::string& LogEntry::raw_data() const
{
    return m_raw_data;
}

std::string LogEntry::message() const
{
    return "Basic message";
}

std::string LogEntry::timestamp() const
{
    return "2025-11-13 12:00:00";
}

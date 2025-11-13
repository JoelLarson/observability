#include "LogEntry.h"

LogEntry::LogEntry(const std::string& raw_data): m_raw_data(raw_data)
{
    // empty
}

const std::string& LogEntry::raw_data() const
{
    return m_raw_data;
}

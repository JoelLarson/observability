#include "LogStorage.h"

#include <algorithm>
#include <optional>

#include "LogEntry.h"

void LogStorage::ingest_log_entry(LogEntry log_entry)
{
    m_entries.push_back(log_entry);
}

std::optional<LogEntry> LogStorage::last_entry()
{
    if (m_entries.empty())
    {
        return std::nullopt;
    }

    return m_entries.back();
}

std::vector<LogEntry> LogStorage::last_entries(int count)
{
    if (m_entries.size() < count)
    {
        return m_entries;
    }

    std::vector result(m_entries.end() - count, m_entries.end());

    std::ranges::reverse(result);

    return result;
}
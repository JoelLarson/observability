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

std::vector<LogEntry> LogStorage::last_entries(const std::size_t count)
{
    if (count == 0 || m_entries.empty())
    {
        return {};
    }

    const std::size_t size = m_entries.size();

    const std::size_t actual_size = std::min(count, size);

    using Diff = std::vector<LogEntry>::difference_type;
    const auto start_iterator = m_entries.end() - static_cast<Diff>(actual_size);

    std::vector result(start_iterator, m_entries.end());

    std::ranges::reverse(result);

    return result;
}
#include "LogStorage.h"

#include <algorithm>
#include <optional>

void LogStorage::ingest_log_entry(const std::string& string)
{
    m_entries.push_back(string);
}

std::optional<std::string> LogStorage::last_entry()
{
    if (m_entries.empty())
    {
        return std::nullopt;
    }

    return m_entries.back();
}

std::vector<std::string> LogStorage::last_entries(int count)
{
    if (m_entries.size() < count)
    {
        return m_entries;
    }

    std::vector result(m_entries.end() - count, m_entries.end());

    std::ranges::reverse(result);

    return result;
}
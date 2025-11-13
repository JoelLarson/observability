#include "log_storage.h"

#include <algorithm>
#include <optional>

void LogStorage::ingest_log_entry(const std::string& string)
{
    m_entries.push_back(string);
}

std::optional<std::string> LogStorage::get_last_entry()
{
    if (m_entries.empty())
    {
        return std::nullopt;
    }

    return m_entries.back();
}

std::vector<std::string> LogStorage::get_last_entries(int count)
{
    std::vector result(m_entries.end() - count, m_entries.end());

    std::ranges::reverse(result);

    return result;
}
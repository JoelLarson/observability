#include "log_storage.h"

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

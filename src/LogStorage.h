#pragma once

#include <optional>
#include <vector>

#include "LogEntry.h"

class LogStorage
{
public:
    LogStorage() = default;

    void ingest_log_entry(LogEntry log_entry);
    std::optional<LogEntry> last_entry();
    std::vector<LogEntry> last_entries(std::size_t count);

private:
    std::vector<LogEntry> m_entries;
};
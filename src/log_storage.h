#pragma once
#include <optional>
#include <vector>
#include <bits/basic_string.h>

class LogStorage
{
public:
    LogStorage() = default;
    void ingest_log_entry(const std::string& string);
    std::optional<std::string> last_entry();
    std::vector<std::string> last_entries(int count);

private:
    std::vector<std::string> m_entries;
};
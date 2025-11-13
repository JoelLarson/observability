#pragma once
#include <optional>
#include <vector>
#include <bits/basic_string.h>

class LogStorage
{
public:
    LogStorage() = default;
    void ingest_log_entry(const std::string& string);
    std::optional<std::string> get_last_entry();

private:
    std::vector<std::string> m_entries;
};
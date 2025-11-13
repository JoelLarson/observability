#pragma once

#include <string>

class LogEntry
{
public:
    explicit LogEntry(std::string raw_data);

    [[nodiscard]] const std::string& raw_data() const;

private:
    std::string m_raw_data;
};

#pragma once

#include <string>

class LogEntry
{
public:
    explicit LogEntry(const std::string& raw_data);

    [[nodiscard]] const std::string& raw_data() const;

private:
    const std::string& m_raw_data;
};

#pragma once

#include <string>

class LogEntry
{
public:
    explicit LogEntry(std::string raw_data);

    [[nodiscard]] const std::string& raw_data() const;
    std::string message() const;
    std::string timestamp() const;

private:
    std::string m_raw_data;
};

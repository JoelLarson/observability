#pragma once

#include <string>

class LogEntry
{
public:
    explicit LogEntry(std::string timestamp, std::string message);
    explicit LogEntry(std::string message);

    [[nodiscard]] const std::string& timestamp() const;
    [[nodiscard]] const std::string& message() const;

private:
    std::string m_timestamp;
    std::string m_message;
};

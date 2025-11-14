#include "LogEntryParser.h"

LogEntry LogEntryParser::parse(const std::string& message)
{
    const auto timestamp_start = message.find('[');

    if (timestamp_start != std::string::npos)
    {
        const auto timestamp_end = message.find(']');

        const auto timestamp = message.substr(timestamp_start + 1, timestamp_end - timestamp_start - 1);

        auto parsed_message = message.substr(timestamp_end + 1);

        if (!parsed_message.empty() && parsed_message.front() == ' ')
        {
            parsed_message.erase(0, 1);
        }

        return LogEntry {
            timestamp,
            parsed_message
        };
    }

    return LogEntry { "", message };
}

#pragma once

#include "LogEntry.h"

class LogEntryParser
{
public:
    LogEntry parse(const std::string& message);
};

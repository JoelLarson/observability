#pragma once
#include <bits/basic_string.h>

class LogStorage
{
public:
    void ingest_log_entry(const std::string& string);
    std::string get_last_entry();
};
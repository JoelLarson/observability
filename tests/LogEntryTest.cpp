#include <catch2/catch_test_macros.hpp>

#include "../src/LogEntry.h"

TEST_CASE("LogEntry::raw_data()")
{
    std::string raw_message = "Log Message";

    const LogEntry entry { raw_message };

    REQUIRE(entry.raw_data() == raw_message);
}
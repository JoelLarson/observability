#include <catch2/catch_test_macros.hpp>

#include "../src/LogEntry.h"

TEST_CASE("LogEntry::raw_data()")
{
    std::string message = "Log Message";

    const LogEntry entry { message };

    REQUIRE(entry.message() == message);
}
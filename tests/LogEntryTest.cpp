#include <catch2/catch_test_macros.hpp>

#include "../src/LogEntry.h"

TEST_CASE("LogEntry")
{
    SECTION("Message is populated on construction")
    {
        std::string message = "Log Message";

        const LogEntry entry { message };

        REQUIRE(entry.message() == message);
    }

    SECTION("Timestamp is populated on construction")
    {
        std::string timestamp = "2025-11-13 12:00:00";

        const LogEntry entry { timestamp, "" };

        REQUIRE(entry.timestamp() == timestamp);
    }
}
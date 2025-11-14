#include <catch2/catch_test_macros.hpp>

#include "../src/LogEntryParser.h"

TEST_CASE("LogEntryParser")
{
    LogEntryParser parser {};

    SECTION("Parse a basic message")
    {
        std::string raw_message = "Basic message";

        const auto log_entry = parser.parse(raw_message);

        REQUIRE(log_entry.message() == raw_message);
    }

    SECTION("Parse a timestamp")
    {
        const std::string raw_message = "[2025-11-13 12:00:00] Basic message";

        const auto log_entry = parser.parse(raw_message);

        REQUIRE(log_entry.message() == "Basic message");
        REQUIRE(log_entry.timestamp() == "2025-11-13 12:00:00");
    }
}
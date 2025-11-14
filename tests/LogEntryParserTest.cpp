#include <catch2/catch_test_macros.hpp>

#include "../src/LogEntryParser.h"

TEST_CASE("LogEntryParser")
{
    LogEntryParser parser {};

    SECTION("Parse a basic message")
    {
        std::string raw_message = "Basic message";

        const auto log_entry = parser.parse(raw_message);

        REQUIRE(log_entry.raw_data() == raw_message);
    }
}
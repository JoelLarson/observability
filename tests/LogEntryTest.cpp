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
}
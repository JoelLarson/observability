#include <catch2/catch_test_macros.hpp>
#include "../src/log_storage.h"

// Log data is streamed into the system as `Timestamp: Message`
// When the data is ingested, it is stored in chronological order from oldest to newest
// When retrieving the last 10 entries, the entries should be newest to oldest

TEST_CASE("LogStorage")
{
    LogStorage storage {};

    SECTION("Ingest single log entry")
    {
        std::string log_entry = "Default Log Entry";

        storage.ingest_log_entry(log_entry);

        auto last_entry = storage.last_entry();

        REQUIRE(last_entry.has_value());
        REQUIRE(last_entry.value() == log_entry);
    }

    SECTION("An empty log store returns nothing")
    {
        const auto entry = storage.last_entry();

        REQUIRE(!entry.has_value());
    }

    SECTION("Multiple log entries are retrieved")
    {
        storage.ingest_log_entry("First Log Entry");
        storage.ingest_log_entry("Second Log Entry");

        const auto entries = storage.get_last_entries(2);

        REQUIRE(entries.size() == 2);
        REQUIRE(entries[0] == "Second Log Entry");
        REQUIRE(entries[1] == "First Log Entry");
    }
}
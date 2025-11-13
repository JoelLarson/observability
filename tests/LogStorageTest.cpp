#include <catch2/catch_test_macros.hpp>
#include "../src/LogStorage.h"
#include "../src/LogEntry.h"

// Log data is streamed into the system as `Timestamp: Message`
// When the data is ingested, it is stored in chronological order from oldest to newest
// When retrieving the last 10 entries, the entries should be newest to oldest

TEST_CASE("LogStorage")
{
    LogStorage storage {};

    SECTION("Ingest single log entry")
    {
        LogEntry log_entry { "Default Log Entry" };

        storage.ingest_log_entry(log_entry);

        auto last_entry = storage.last_entry();

        REQUIRE(last_entry.has_value());
        REQUIRE(last_entry.value().raw_data() == log_entry.raw_data());
    }

    SECTION("An empty log store returns nothing")
    {
        const auto entry = storage.last_entry();

        REQUIRE(!entry.has_value());
    }

    SECTION("last_entries is empty when no logs ingested")
    {
        const auto entries = storage.last_entries(1);

        REQUIRE(entries.empty());
    }

    SECTION("Multiple log entries are retrieved")
    {
        storage.ingest_log_entry(LogEntry("First Log Entry"));
        storage.ingest_log_entry(LogEntry("Second Log Entry"));

        const auto entries = storage.last_entries(2);

        REQUIRE(entries.size() == 2);
        REQUIRE(entries[0].raw_data() == "Second Log Entry");
        REQUIRE(entries[1].raw_data() == "First Log Entry");
    }
}
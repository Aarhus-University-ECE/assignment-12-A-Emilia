#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "duration.hpp"

TEST_CASE("Constructor") {          // Sets the time to different values and checks it.
  Duration d;
  REQUIRE(d.getDuration() == 0);
  d = Duration(69);
  REQUIRE(d.getDuration() == 69);
  d = Duration(420);
  REQUIRE(d.getDuration() == 420);
  d = Duration(1337);
  REQUIRE(d.getDuration() == 1337);
  d = Duration(42);
  REQUIRE(d.getDuration() == 42);
}

TEST_CASE("Tick") {                // Checks tick.
  Duration d;
  d.tick();
  REQUIRE(d.getDuration() == 1);

  d.tick(15);
  REQUIRE(d.getDuration() == 16);
}

TEST_CASE("Alarm") {               // Checks alarm.
  Duration d;
  d = Duration(42);                // Sets time to 42.
  
  d.setAlarm(69);                  // Sets the alarm to 69.
  REQUIRE(d.tick() == false);      // Alarm has not yet been reached.
  REQUIRE(d.tick(27) == true);     // Alarm has been reached.
  REQUIRE(d.tick(16) == false);    // Value in the past that should be false.
}
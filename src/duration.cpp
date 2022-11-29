#include "duration.hpp"
#include <assert.h>

int Duration::getDuration() { return time; }

Duration::Duration() { time = 0; }

Duration::Duration(int t) {
  assert(t >= 0);
  time = t;
}

bool Duration::tick() {
  time++;
  return checkAndUpdateAlarm();
}

bool Duration::tick(int dt) {
  assert(dt >= 0);
  time += dt;

  return checkAndUpdateAlarm();
}

void Duration::setAlarm(int t) {
  assert(t >= time);
  alarm = t;
  alarmHasBeenSet = true;
}

bool Duration::checkAndUpdateAlarm() {
  if (time > alarm && alarmHasBeenSet == true) {
    alarm = 0;
    alarmHasBeenSet = false;
    return true;
  } else {
    return false;
  }
}
Duration::~Duration() {}
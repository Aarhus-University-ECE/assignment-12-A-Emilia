#ifndef __DURATION_H_
#define __DURATION_H_
#include <stdbool.h>

class Duration {
private:
  int time;
  int alarm = 0;
  bool alarmHasBeenSet = false;

  bool checkAndUpdateAlarm();

public:
  Duration();
  Duration(int t);

  int getDuration();
  bool tick();
  bool tick(int dt);
  void setAlarm(int t);

  ~Duration();
};

#endif
#pragma once
#include "WorkItem.h"

class SingleTask : public WorkItem{
private:
  long time;
  long duration;

public: 
  SingleTask(const std::string& name, long _time, long _duration) : WorkItem(name){
    time = _time;
    duration = _duration;
  }

  bool status(long now) const {
    return time + duration <= now;
  }
};
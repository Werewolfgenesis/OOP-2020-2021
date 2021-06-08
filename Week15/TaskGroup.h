#pragma once
#include "SingleTask.h"
#include <vector>
#include <iostream>

class TaskGroup : public WorkItem{
private:
  std::vector<WorkItem*> tasks;

public:
TaskGroup(const std::string& name) : WorkItem(name){}
  bool status(long now) const {
    for(auto task : tasks) {
      if(!task->status(now)) {
        return false;
      }
    }

    return true;
  }

  void addTask(WorkItem* task) {
    if(task) {
      tasks.push_back(task);
    }
  }

  void print() const {
    for(auto task : tasks) {
      std::cout<<task->name()<<std::endl;
    }
  }
};
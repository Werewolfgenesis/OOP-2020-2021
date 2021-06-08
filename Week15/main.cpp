#include "Test.h"
#include "TaskGroup.h"

bool allDone(int size, WorkItem** tasks, int now) {
  for(int i = 0; i < size; ++i) {
    if(!tasks[i]->status(now)) {
      return false;
    }
  }
  return true;
}

int main()
{
  std::cout<<"TASK 1\n\n";
  std::string question = "Will we finish FMI?";
  std::string first[2];
  first[0] = std::string("false");
  first[1] = std::string("FALSE");
  ClosedQuestion cq(2, question, 100, first, "false");
  std::cout << cq.ask() << std::endl;
  OpenQuestion oq("How many turns are in the world", "2", 12012);
  std::cout<<oq.ask() << std::endl;

  std::vector<Question*> questions;
  questions.push_back(&cq);
  questions.push_back(&oq);

  Test test(questions);
  test.ask();

  std::cout<<"TASK 2\n\n";
  SingleTask st("Just a single task", 7200000, 3600000);
  std::cout<<st.name()<<"\nIs done: "<<std::boolalpha<<st.status(9000000)<<std::endl;
  TaskGroup tg("Just a task group");
  tg.addTask(&st);
  std::cout<<tg.status(9000000);
  TaskGroup tg2("Second task group");
  tg2.addTask(&st);
  tg2.addTask(&tg);
  std::cout<<std::boolalpha<<tg2.status(18000000);

  WorkItem** items = new WorkItem*[3];
  items[0] = &st;
  items[1] = &tg;
  items[2] = &tg2;

  std::cout<<allDone(sizeof(items) / sizeof(WorkItem*), items, 9000000)<<std::endl;
  std::cout<<allDone(3, items, 18000000)<<std::endl;


  delete[] items;

  return 0;
}
//1h -> 60m -> 3600s -> 3600000ms
//1970-1-1 00:00 -> 0ms
//1970-1-1 01:00 -> 3600000ms
//1970-1-1 02:00 -> 7200000ms
//1970-1-1 02:30 -> 9000000ms
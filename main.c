#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define TASK_TITLE_SIZE 64
#define TASK_NOTE_SIZE 64
struct Task{
  char title[TASK_TITLE_SIZE];
  char note[TASK_NOTE_SIZE];
  uint16_t priority;
  uint16_t id;
};

struct Task Task_create(
  const char *title,
  const char *note,
  uint16_t priority,
  uint16_t id
)
{
  struct Task task = {0};

  strncpy(task.title,title,TASK_TITLE_SIZE);
  strncpy(task.note,note,TASK_NOTE_SIZE);
  task.priority = priority;
  task.id = id;

  return task; 
}

void Task_show(struct Task *task){
  printf("title:%s\n",task->title);
  printf("note:%s\n",task->note);
  printf("priority:%u\n",task->priority);
  printf("id:%u\n",task->id);
}

int main(int argc,char *argv[]){
  
  struct Task task = {0};

  if(argc >= 2){
    if (strncmp(argv[1],"add",3) == 0) {
      if (argc >= 3) { 
        task = Task_create(argv[2], argv[3], 99, 1);
      } else { 
        task = Task_create(argv[2], "", 99, 1);
      }
    }
  }

  Task_show(&task);

  return EXIT_SUCCESS;
}

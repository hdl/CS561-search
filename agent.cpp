#include "task.h"
#include "bfs.h"

int main()
{
   Task task_info("input.txt");
   task_info.PrintTaskInfo();
   // run BFS
   if (task_info.task == 1){
       BFS bfs(task_info);
       task_info.CheckFinish(bfs.finished);
       task_info.PrintExpansion(bfs.expansion_q);
       task_info.PrintOutput();
       task_info.PrintPathCost();
   }

   
   return (1); 
}


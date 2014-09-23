#include "task.h"
#include "bfs.h"
#include "common.h"


bool compare_by_name(int a, int b){
	return task_info_p->nodes[a].name.compare(task_info_p->nodes[b].name) < 0;
};

Task * task_info_p;

int main()
{
   Task task_info("input.txt");
   task_info_p=&task_info;

   task_info.PrintTaskInfo();
   if (task_info.task == 1){
       BFS bfs(task_info);
       task_info.CheckFinish(bfs.finished);
       task_info.PrintExpansion(bfs.expansion_q);
       task_info.PrintOutput();
       task_info.PrintPathCost();
   }
   
   return (1); 
}


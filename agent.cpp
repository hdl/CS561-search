#include "task.h"
#include "bfs.h"
#include "dfs.h"
#include "ucs.h"
#include "common.h"

Task * task_info_p;

int main()
{
   Task task_info("input.txt");
   task_info_p=&task_info;

   //task_info.PrintTaskInfo();
   if (task_info.task == 1){
       BFS bfs(task_info);
       task_info.CheckFinish(bfs.finished);
       task_info.PrintExpansion(bfs.expansion_q);
       task_info.PrintOutput();
       task_info.PrintPathCost();
   }
   if (task_info.task == 2){
       DFS dfs(task_info);
       task_info.CheckFinish(dfs.finished);
       task_info.PrintExpansion(dfs.expansion_q);
       task_info.PrintOutput();
       task_info.PrintPathCost();
   }
   if (task_info.task == 3){
       UCS ucs(task_info);
       task_info.CheckFinish(ucs.finished);
       task_info.PrintExpansion(ucs.expansion_q);
       task_info.PrintOutput();
       task_info.PrintPathCost();
   }
   return (1); 
}

bool compare_by_name(int a, int b){
	return task_info_p->nodes[a].name.compare(task_info_p->nodes[b].name) < 0;
}

bool compare_by_cost_name(int a, int b){
	if (task_info_p->nodes[a].path_cost < task_info_p->nodes[b].path_cost)
		return 1;
	else if (task_info_p->nodes[a].path_cost == task_info_p->nodes[b].path_cost)
	    return task_info_p->nodes[a].name.compare(task_info_p->nodes[b].name) < 0;
	else 
		return 0;
}

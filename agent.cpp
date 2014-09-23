#include "task.h"
#include "bfs.h"
#include "dfs.h"
#include "common.h"

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
   if (task_info.task == 2){
       DFS dfs(task_info);
       task_info.CheckFinish(dfs.finished);
       task_info.PrintExpansion(dfs.expansion_q);
       task_info.PrintOutput();
       task_info.PrintPathCost();
   }
   
   return (1); 
}

bool compare_by_name(int a, int b){
	return task_info_p->nodes[a].name.compare(task_info_p->nodes[b].name) < 0;
};

void sort_children(int parent_index, vector<int> &temp_children){
	int i;
    for(i = 0; i<task_info_p->node_number; i++)
    	{
    		if(task_info_p->distance[parent_index][i] != 0 && task_info_p->nodes[i].visited == 0){
    			temp_children.push_back(i);
    		}
    	}
	sort(temp_children.begin(), temp_children.end(), compare_by_name);
};



#include "task.h"
#include "bfs.h"

BFS::BFS(Task &task_info)
{
        queue<int> Q;
	Q.push(task_info.src_index);
	expansion_q.push(task_info.src_index);
	task_info.nodes[task_info.src_index].visited = 1;

	while(!Q.empty()){
		int parent_index = Q.front();
		Q.pop();
		for(int i = 0; i<task_info.node_number; i++)
		{
			if(task_info.distance[parent_index][i] != 0 && task_info.nodes[i].visited == 0){
				Q.push(i);
				task_info.nodes[i].visited=1;
				task_info.nodes[i].parent=parent_index;
				// task_info.nodes[i].path_cost=task_info.nodes[parent_index].path_cost + 1;
				task_info.nodes[i].path_cost=task_info.nodes[parent_index].path_cost + task_info.distance[parent_index][i] ;
				expansion_q.push(i);
				if(i == task_info.dst_index){
					finished = 1;
					return;
				}
			}
		}
	}
}


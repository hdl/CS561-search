#ifndef BFS_H
#define BFS_H
#include "common.h"
#include "task.h"
using namespace std;
class BFS
{
public: 
    void BFS(Task &task_info);
    void PrintExpansion();
    void PrintOutput();
    void PrintPathCost();
};

void BFS::BFS(Task &task_info)
{
	node_info src_node = {
		.index = task_info.node_src_index;
		.path_cost = 0;
		.parent = 0;
		.visited = 0;
	};
        queue<node_info> Q;
	Q.push(src_node);
	src_node.visited = 1;

	while(!Q.empty()) {
		node_info node_parent = Q.front();
		Q.pop();
		for(i = 0; i<task_info.node_number; i++)
		{
			if(task_info.distance[node_parent.index][i] != 0){
                        	node_info *node_child = new node_info;
				node_child->index = i;
				node_child->path_cost = node_parent + 1;
			        node_child->parent = node_parent.index;
			        node_child->visited = 1;	
				Q.push(*node_child);
			}
		}
	}



}

#endif

#include "task.h"
#include "dfs.h"

DFS::DFS(Task &task_info)
{
    stack<int> S;
	expansion_q.push(task_info.src_index);
	task_info.nodes[task_info.src_index].visited = 1;
	vector<int> temp_children;
	int parent_index;
	int i;
	S.push(task_info.src_index);

	while(!S.empty()){
		parent_index = S.top();
		S.pop();

		sort_children(parent_index, temp_children);
		// real dfs loop
        i=0;
        cout << "PUSH alphtical: " << task_info.nodes[temp_children[i]].name << endl; 
        S.push(temp_children[i]);
        task_info.nodes[temp_children[i]].visited=1;
        task_info.nodes[temp_children[i]].parent=parent_index;
        task_info.nodes[temp_children[i]].path_cost=task_info.nodes[parent_index].path_cost + task_info.distance[parent_index][temp_children[i]] ;
        expansion_q.push(temp_children[i]);
        cout << "Cost so far: " << task_info.nodes[temp_children[i]].path_cost << endl;
        if(temp_children[i] == task_info.dst_index){
        	finished = 1;
        	return;
        }
		temp_children.clear();
	}
}

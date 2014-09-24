#include "task.h"
#include "bfs.h"

BFS::BFS(Task &task_info)
{
    queue<int> Q;
	vector<int> temp_children;
	int parent_index;
	int i;
	Q.push(task_info.src_index);
	task_info.nodes[task_info.src_index].visited=1;

	while(!Q.empty()){
		parent_index = Q.front();
		Q.pop();
		cout << "POP: " << task_info.nodes[parent_index].name << endl; 
        expansion_q.push(parent_index);
        if(parent_index == task_info.dst_index){
        	finished = 1;
        	return;
        }
		sort_children(parent_index, temp_children);
		if (temp_children.size()==0){
			cout << "no children, continue" << endl;
		    continue;
		}
		// real bfs loop
		for(i = 0; i<temp_children.size(); i++)
		{
		    cout << "PUSH: " << task_info.nodes[temp_children[i]].name; 
			Q.push(temp_children[i]);
			task_info.nodes[temp_children[i]].parent=parent_index;
			task_info.nodes[temp_children[i]].path_cost=task_info.nodes[parent_index].path_cost + task_info.distance[parent_index][temp_children[i]] ;
			task_info.nodes[temp_children[i]].visited=1;
        	cout << " Cost: " << task_info.nodes[temp_children[i]].path_cost << endl;
		}
		temp_children.clear();
		// sort Q
	}
}

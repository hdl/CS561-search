#include "task.h"
#include "dfs.h"

DFS::DFS(Task &task_info)
{
    stack<int> S;
	vector<int> temp_children;
	int parent_index;
	int i;
	S.push(task_info.src_index);

	while(!S.empty()){
		parent_index = S.top();
		S.pop();
		task_info.nodes[parent_index].visited=1;
        expansion_q.push(parent_index);
        if(parent_index == task_info.dst_index){
        	finished = 1;
        	return;
        }

		sort_children(parent_index, temp_children);
		if (temp_children.size()==0)
			return;

		// real dfs loop
        for(i = temp_children.size()-1; i>=0; i--) {
            cout << "PUSH alphtical: " << task_info.nodes[temp_children[i]].name << endl; 
        	S.push(temp_children[i]);
        	task_info.nodes[temp_children[i]].parent=parent_index;
        	task_info.nodes[temp_children[i]].path_cost=task_info.nodes[parent_index].path_cost + task_info.distance[parent_index][temp_children[i]] ;
        	cout << "Cost so far: " << task_info.nodes[temp_children[i]].path_cost << endl;
        }
        temp_children.clear();
        }
}

#include "task.h"
#include "dfs.h"

DFS::DFS(Task &task_info)
{
    stack<int> S;
	vector<int> temp_children;
	int parent_index;
	int i;
	S.push(task_info.src_index);
// it's possible that a node pop out two times 
	while(!S.empty()){
		parent_index = S.top();
		S.pop();
		cout << "POP: " << task_info.nodes[parent_index].name << endl; 
		task_info.nodes[parent_index].visited=1;
        expansion_q.push(parent_index);
        if(parent_index == task_info.dst_index){
        	finished = 1;
        	return;
        }

		sort_children(parent_index, temp_children);
		if (temp_children.size()==0){
			cout << "no children!" << endl;
			continue;
		}

		// real dfs loop
        for(i = temp_children.size()-1; i>=0; i--) {
            cout << "PUSH " << task_info.nodes[temp_children[i]].name; 
        	S.push(temp_children[i]);
		    task_info.nodes[temp_children[i]].visited=1;
        	task_info.nodes[temp_children[i]].parent=parent_index;
        	task_info.nodes[temp_children[i]].path_cost=task_info.nodes[parent_index].path_cost + task_info.distance[parent_index][temp_children[i]] ;
        	cout << " Cost: " << task_info.nodes[temp_children[i]].path_cost << endl;
        }
        temp_children.clear();
    }
}

void sort_children(int parent_index, vector<int> &temp_children){
	int i;
    for(i = 0; i<task_info_p->node_number; i++)
    	{
    		if(task_info_p->distance[parent_index][i] != 0 && task_info_p->nodes[i].visited == 0){
    			temp_children.push_back(i);
    		}
    	}
	sort(temp_children.begin(), temp_children.end(), compare_by_name);
}



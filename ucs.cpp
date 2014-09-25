#include "task.h"
#include "ucs.h"
bool in_vector(int a, vector<int> &nodes_index)
{
	for(int i=0; i<nodes_index.size(); i++){
		if(a==nodes_index[i])
			return 1;
	}
	return 0;
}
bool remove_from_vector(int a, vector<int> &a_vector)
{
	for(int i=0; i<a_vector.size(); i++){
		if(a==a_vector[i]){
			a_vector.erase(a_vector.begin()+i);
			return 1;
		}
	}
	// cout << "can find this child in closed vector" << endl;
	return 0;
}
UCS::UCS(Task &task_info)
{
    vector<int> opened_vector;
    vector<int> closed_vector;
	vector<int> temp_children;
	// store index
	int parent_index;
	int i;
	
	opened_vector.push_back(task_info.src_index);

	while(!opened_vector.empty()){
		parent_index = opened_vector[0];
		opened_vector.erase(opened_vector.begin());
        // cout << "POP: " << task_info.nodes[parent_index].name<< endl;
		task_info.nodes[parent_index].close_path_cost=task_info.nodes[parent_index].path_cost;
		closed_vector.push_back(parent_index);
		expansion_q.push(parent_index);

		if(parent_index == task_info.dst_index){
			finished = 1;
			return;
		}

	    // get children	
		for(i = 0; i<task_info.node_number; i++)
		{
	        if(task_info.distance[parent_index][i] != 0){
				temp_children.push_back(i);
			}
		}

		if (temp_children.size()==0){
			// cout << "no children " << endl;
		    sort(opened_vector.begin(), opened_vector.end(), compare_by_cost_name);
			continue;
		}

		// real ucs loop
		for(i = 0; i<temp_children.size(); i++)
		{
			int child = temp_children[i];
			if(in_vector(child, opened_vector) && in_vector(child, closed_vector)){
				// cout << child << " in both open and close" << endl;
				return;
			}else if(!in_vector(child, opened_vector) && !in_vector(child, closed_vector)){
				opened_vector.push_back(child);
				task_info.nodes[child].path_cost= task_info.nodes[parent_index].path_cost+task_info.distance[parent_index][child];
				task_info.nodes[child].parent = parent_index;
                // cout << "PUSH: " << task_info.nodes[child].name << endl;
			}
			else if(in_vector(child, opened_vector)){
				if(task_info.nodes[parent_index].path_cost+task_info.distance[parent_index][child]< task_info.nodes[child].path_cost){
					// no push, because it already in opened_vector
					task_info.nodes[child].path_cost= task_info.nodes[parent_index].path_cost+task_info.distance[parent_index][child];
				    task_info.nodes[child].parent = parent_index;
				    // this new path to a child is better, set the new path_cost and parent for this child
                    // cout << "update open: " << task_info.nodes[child].name << endl;
				}
			}else if(in_vector(temp_children[i], closed_vector)){
				if(task_info.nodes[parent_index].path_cost+task_info.distance[parent_index][child]< task_info.nodes[child].close_path_cost){
					opened_vector.push_back(child);
					task_info.nodes[child].path_cost= task_info.nodes[parent_index].path_cost+task_info.distance[parent_index][child];
				    task_info.nodes[child].parent = parent_index;
					// has a better path for a closed node, recovery it. set new path_cost and parent
					// remove it from closed_vector
					remove_from_vector(child, closed_vector);
                    // cout << "get from close: " << task_info.nodes[child].name << endl;
				}
				    
			}
		}
		temp_children.clear();
		sort(opened_vector.begin(), opened_vector.end(), compare_by_cost_name);
	}
}

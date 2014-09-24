#include "task.h"
#include "ucs.h"
get_children(node_info &parent_node, vector<node_info> &temp_children)
{
    int i;
    for(i = 0; i<task_info_p->node_number; i++)
    {
    	if(task_info_p->distance[parent_node.index][i] != 0 && task_info_p->nodes[i].visited == 0){
    		temp_children.push_back(task_info_p->nodes[i]);
			temp_children.back().path_cost = parent_node.path_cost + task_info_p->distance[parent_node.index][i]; 
    	}
    }

};

// path_cost in priority_queue are stored in nodes
// path_cost in temp_children and priority_queue should different
UCS::UCS(Task &task_info)
{
    priority_queue<node_info> Q;
	queue<node_info> temp_children;
	node_info temp_child;
	vector<int> close_nodes_index;
	vector<int> open_nodes_index;
	vector<int>::iterator it;
	node_info parent_node;
	int i;
	// push into Q should follow with: 1.open_index
	Q.push(task_info.nodes[task_info.src_index]);
	open_nodes_index.push_back(task_info.src_index);

	while(!Q.empty()){
		parent_node = Q.front();
		Q.pop();
	    // pop out Q should follow with: 0. update path_cost 1.open_index.erase, 2.close_index.push 3.nodes[].visited 4.expansion_q
		parent_node.path_cost = node_info.nodes[parent_node.index].path_cost;
		it = find(open_nodes_index.begin(), open_nodes_index.end(), parent_node.index);
		open_nodes_index.erase(it);
		close_nodes_index.push_back(parent_node.index);
	    task_info.nodes[task_info.src_index].visited=1;
	    expansion_q.push(task_info.src_index);
		cout << "POP: " << task_info.nodes[parent_node.index].name << endl; 
		if(parent_node.index == task_info.dst_index){
			finished = 1;
			return;
		}
		get_children(parent_node, temp_children);
		if (temp_children.size()==0){
			cout << "no children!" << endl;
			return;
		}

		// real ucs loop
		while(!temp_children.empty())
		{
			temp_child = temp_children.front();
			temp_children.pop();

			if(temp_child.in_vector(open_nodes_index) && temp_child.in_vector(close_nodes_index)){
				cout << "child in both open and close" << endl;
				return;
			}else 
			if(!temp_child.in_vector(open_nodes_index) && !temp_child.in_vector(close_nodes_index)){
				// temp_child.path_cost=parent_node.path_cost+task_info.distance[parent_node.index][temp_child.index];
			    // distance already set	
				open_nodes_index.push_back(temp_child.index);
				Q.push(temp_child);
			}else
			if(temp_child.in_vector(open_nodes_index)){
				if (temp_child.path_cost < task_info.nodes[temp_child.index].path_cost){
					
				}
			}else

			
		    cout << "PUSH alphtical: " << task_info.nodes[temp_children[i]].name << endl; 
			Q.push(temp_children[i]);
			task_info.nodes[temp_children[i]].parent=parent_node;
			task_info.nodes[temp_children[i]].path_cost=task_info.nodes[parent_node].path_cost + task_info.distance[parent_node][temp_children[i]] ;
			task_info.nodes[temp_children[i]].visited=1;
		    expansion_q.push(temp_children[i]);
		    if(temp_children[i] == task_info.dst_index){
		    	finished = 1;
		    	return;
		    }
        	cout << "Cost: " << task_info.nodes[temp_children[i]].path_cost << endl;
		}
		temp_children.clear();
	}
}

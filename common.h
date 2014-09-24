#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include "task.h"
using namespace std;

typedef struct node_info_t{
    string name;
    int index;
    int depth;
    int path_cost;
    int parent;
    bool visited;
	bool in_vector(vector<int> nodes_index)
	{
		for(int i=0; i<nodes_index.size(); i++){
			if(index==nodes_index[i])
				return 1;
		}
		return 0;
	}
}node_info;

extern bool compare_by_name(int a, int b);
extern void sort_children(int parent_index, vector<int> &temp_children);

#endif

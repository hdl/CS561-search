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
    int path_cost; //algorithm path, not real cost
	int close_path_cost; // the cost when it close
    int parent;
    bool visited;
}node_info;

extern bool compare_by_cost_name(int a, int b);
extern bool compare_by_name(int a, int b);
extern void sort_children(int parent_index, vector<int> &temp_children);

#endif

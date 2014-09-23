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
}node_info;

#endif

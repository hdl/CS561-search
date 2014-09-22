#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef struct node_info_t{
    string name;
    int index;
    int depth;
    int path_cost;
    int parent;
    int visited;
}node_info;
#endif

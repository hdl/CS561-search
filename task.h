#ifndef TASK_H
#define TASK_H
#include "common.h"
using namespace std;
class Task
{
public: 
    int task;
    int node_number;
    int src_index;
    int dst_index;
    string src_name;
    string dst_name;
    vector<node_info> nodes;
    vector< vector<int> > distance;

    Task(const string &inputFileName);
    void PrintTaskInfo();
};
#endif

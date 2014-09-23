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
    ofstream outputFile;

    Task(const string &inputFileName);
    void PrintTaskInfo();
    void CheckFinish(bool finished);
    void PrintExpansion(queue<int> Q);
    void PrintOutput();
    void PrintPathCost();
};
extern Task * task_info_p;
extern bool compare_by_name(int a, int b);
#endif

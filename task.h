#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Task
{
public: 
    int task;
    string node_src;
    int node_src_index;
    string node_des;
    int node_des_index;
    int node_number;
    vector<string> node_names;
    vector< vector<int> > distance;

    Task(const string &inputFileName);
    void PrintTaskInfo();
};
#endif

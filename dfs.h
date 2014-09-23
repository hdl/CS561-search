#ifndef DFS_H
#define DFS_H
#include "common.h"
#include "task.h"
using namespace std;
class DFS
{
public:
    bool finished;
    queue<int> expansion_q;    
    DFS(Task &task_info);
};

#endif

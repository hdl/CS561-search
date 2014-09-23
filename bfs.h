#ifndef BFS_H
#define BFS_H
#include "common.h"
#include "task.h"
using namespace std;
class BFS
{
public:
    bool finished;
    queue<int> expansion_q;    
    BFS(Task &task_info);
};

#endif

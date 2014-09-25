#ifndef UCS_H
#define UCS_H
#include "common.h"
#include "task.h"
using namespace std;
class UCS
{
public:
    bool finished;
    queue<int> expansion_q;    
    UCS(Task &task_info);
};

#endif

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include "task.h"

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()))

using namespace std;

int main()
{
   Task task_info("input.txt");
   task_info.PrintTaskInfo();
   // run BFS
   if (task_info.task == 1){
   }
   return (1); 
}


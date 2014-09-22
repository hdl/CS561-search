#include "task.h"
#include "common.h"
using namespace std;

Task::Task(const string &inputFileName)
{
     int i=0, j=0;
     string line;
     stringstream ss;
     fstream inputFile;
     inputFile.open(inputFileName, ios::in);
     getline(inputFile, line);
     task=stoi(line, nullptr);
     getline(inputFile, src_name);
     getline(inputFile, dst_name);
     if(!src_name.empty() && src_name[src_name.size() - 1]=='\r')
         src_name.erase(src_name.size()-1);
     if(!dst_name.empty() && dst_name[dst_name.size() - 1]=='\r')
         dst_name.erase(dst_name.size()-1);
     getline(inputFile, line);
     node_number=stoi(line, nullptr);
     nodes.resize(node_number);
     for(i = 0; i < node_number; i++){
         nodes[i].index = i;
         getline(inputFile, nodes[i].name);
	 if(!nodes[i].name.empty() && nodes[i].name[nodes[i].name.size() - 1]=='\r'){
             nodes[i].name.erase(nodes[i].name.size()-1);
	 }
     }

     distance.resize(node_number);
     for(i = 0; i < node_number; i++){
         distance[i].resize(node_number);
         getline(inputFile, line);
         ss.str(line);
         for(j = 0; j < node_number; j++){
               ss >> distance[i][j];
         }
     }
     inputFile.close();
     // set src/dst node index
     int src_flag=0, dst_flag=0;
     for(i = 0; i < node_number; i++){
    	 if(nodes[i].name==src_name){
    	     src_index=i;
	     src_flag=1;	
    	 } 
    	 if(nodes[i].name==dst_name){
             dst_index=i; 
             dst_flag=1; 
    	 } 
     }
     if (src_flag!=1 || dst_flag!=1){
	 cout << "bad src/dst index" << endl;
	 exit(0);
     }
}

void Task::PrintTaskInfo()
{
     int i, j;
     cout << task << endl;
     cout << src_index << nodes[src_index].name << endl;
     cout << dst_index << nodes[dst_index].name << endl;
     cout << node_number << endl;
     for(i = 0; i < node_number; i++){
         cout << i << nodes[i].index << nodes[i].name << endl;
     }
     for(i = 0; i < node_number; i++){
         for(j = 0; j < node_number; j++){
               cout << distance[i][j] << " ";
         }
         cout << endl;
     }
}
void Task::CheckFinish(bool finished)
{
	outputFile.open("output.txt");
	if(finished == 0){
		outputFile << "NoPathAvailable" << endl;
		exit(0);	
	}
		
}

void Task::PrintExpansion(queue<int> Q)
{
	int i;
	while(Q.size()!=1){
		i=Q.front();
		Q.pop();
		outputFile << nodes[i].name << "-";
	}
	i = Q.front();
	Q.pop();
	outputFile << nodes[i].name << endl;
}

void Task::PrintOutput()
{
	stack<int> S;
	int i;
	i = dst_index;
	while(i != src_index) {
		S.push(i);
		i = nodes[i].parent;
	}
	outputFile << nodes[i].name << "-" << nodes[S.top()].name << "-";
	S.pop();
	while(S.size()!=1){
		outputFile << nodes[S.top()].name << "-";
		S.pop();
	}
	outputFile << nodes[S.top()].name << endl;
}
void Task::PrintPathCost()
{
	outputFile << nodes[dst_index].path_cost;
	outputFile.close();
}

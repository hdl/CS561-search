#include "task.h"
#include "common.h"
using namespace std;

Task::Task(const string &inputFileName)
{
     int i=0, j=0;
     string line;
     stringstream ss;
     fstream inputFile;
     inputFile.open(inputFileName.c_str());
     getline(inputFile, line);
     task=atoi(line.c_str());
     getline(inputFile, src_name);
     getline(inputFile, dst_name);
     if(!src_name.empty() && src_name[src_name.size() - 1]=='\r')
         src_name.erase(src_name.size()-1);
     if(!dst_name.empty() && dst_name[dst_name.size() - 1]=='\r')
         dst_name.erase(dst_name.size()-1);
     getline(inputFile, line);
     node_number=atoi(line.c_str());
     nodes.resize(node_number);
     for(i = 0; i < node_number; i++){
         nodes[i].index = i;
         nodes[i].path_cost = 0;
         nodes[i].close_path_cost = 0;
         nodes[i].parent = 0;
         nodes[i].in_open= 0;
         nodes[i].in_close= 0;
         nodes[i].disable= 0;
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
	 // cout << "bad src/dst index" << endl;
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
	if(finished == 0){
		outputFile << "NoPathAvailable" << endl;
		exit(0);	
	}
		
}

void Task::PrintExpansion(queue<int> Q)
{
	int i;
	outputFile.open("output.txt");
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
    int parent_index=nodes[dst_index].parent;
    string output=nodes[dst_index].name+"\n";	
	while(parent_index!=src_index){
        output=nodes[parent_index].name+'-'+output;	
		parent_index = nodes[parent_index].parent;
	}
    output=nodes[parent_index].name+'-'+output;	
	outputFile << output;
}
void Task::PrintPathCost()
{
	int child_index=dst_index;
    int parent_index=nodes[dst_index].parent;
    int real_path_cost = 0;	
	while(parent_index!=src_index){
		real_path_cost += distance[parent_index][child_index];
		child_index = parent_index;
		parent_index = nodes[child_index].parent;
	}
	real_path_cost += distance[src_index][child_index];
	outputFile << real_path_cost;
	outputFile.close();
}

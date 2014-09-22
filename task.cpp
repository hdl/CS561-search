#include "task.h"
#include "common.h"
using namespace std;

// return find(nodes.begin(), nodes.end(), node) - nodes.begin();

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
         getline(inputFile, line);
         node_number=stoi(line, nullptr);
	 nodes.resize(node_number);
         // memset(&nodes, 0, node_number * sizeof(node_info));
	 // cout << node_number << "size:" << nodes.size() <<endl;
         for(i = 0; i < node_number; i++){
	     nodes[i].index = i;
             getline(inputFile, nodes[i].name);
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
         for(i = 0; i < node_number; i++){
		 if(nodes[i].name==src_name){
			src_index=i; 
		 } 
		 if(nodes[i].name==dst_name){
			dst_index=i; 
		 } 
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

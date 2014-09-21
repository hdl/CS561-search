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

    Task(const string &inputFileName)
    {
         int i=0, j=0;
         string line;
	 stringstream ss;
         fstream inputFile;
         inputFile.open(inputFileName, ios::in);
         getline(inputFile, line);
         task=stoi(line, nullptr);
         getline(inputFile, node_src);
         getline(inputFile, node_des);
         getline(inputFile, line);
         node_number=stoi(line, nullptr);
	 node_names.resize(node_number);
         for(i = 0; i < node_number; i++){
             getline(inputFile, node_names[i]);
         }
	 node_src_index=find(node_names.begin(), node_names.end(), node_src) - node_names.begin();
	 node_des_index=find(node_names.begin(), node_names.end(), node_des) - node_names.begin();

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
    }
    void PrintTaskInfo()
    {
	 int i, j;
	 cout << task << endl;
	 cout << node_src_index << node_names[node_src_index] << endl;
	 cout << node_des_index << node_names[node_des_index] << endl;
	 cout << node_number << endl;
         for(i = 0; i < node_number; i++){
	     cout << node_names[i] << endl;
         }
	 for(i = 0; i < node_number; i++){
             for(j = 0; j < node_number; j++){
                   cout << distance[i][j] << " ";
	     }
	     cout << endl;
	 }
    }

};

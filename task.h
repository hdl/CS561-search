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
    int node_src_it;
    string node_des;
    int node_des_it;
    int node_number;
    vector<string> node_names;
    vector< vector<int> > distance;

    Task(string &inputFileName)
    {
         int i=0, j=0;
         string line;
	 stringstream ss;
         fstream inputFile;
         inputFile.open(inputFileName, ios::in);
         inputFile.getline(inputFile, line);
         task=stoi(line, nullptr);
         inputFile.getline(inputFile, node_src);
         inputFile.getline(inputFile, node_des);
         inputFile.getline(inputFile, line);
         node_number=stoi(line, nullptr);
         for(i = 0; i < node_number; i++){
             inputFile.getline(inputFile, node_names[i]);
         }
	 distance.resize(node_number);
         for(i = 0; i < node_number; i++){
	     distance[i].resize(node_number);
             inputFile.getline(inputFile, line);
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
	 cout << node_src << endl;
	 cout << node_des << endl;
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

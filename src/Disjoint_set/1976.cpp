#include<string>
#include<iostream>
#include<vector>
#include <sstream>

using namespace std;

int findParent(vector<int> & parent, int target){
    if(parent[target] == target){
        return target;
    }

    return parent[target] = findParent(parent,parent[target]);
}

void unionParent(vector<int> & parent, int a, int b){
    int parentA = parent[a];
    int parentB = parent[b];
    
    if( parentA == parentB){
        return;
    }
    else if(parentA < parentB){
        parent[parentB] = parentA;
    }
    else{
        parent[parentA] = parentB;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    int N,M;
    cin >> N;
    cin >> M;
    
    vector<int> path;
    vector<int> parent;

    for(int i = 0; i<N;i++){
        parent.push_back(i);
    }
    cin.ignore();

    for(int i = 0; i<N; i++){
        vector<int> graph;

        string pathString = "";
        getline(cin,pathString);
        istringstream iss(pathString);
        string token;
        
        while(getline(iss,token,' ')){
            graph.push_back(stoi(token));
        }

        // graph.push_back(a);
        // graph.push_back(b);
        // graph.push_back(connect);
        for(int j = 0; j<graph.size(); j++){
            if(graph[j] == 1){
                unionParent(parent,i,j);
            }
        }

        //cout << i << endl;
    }

    string pathString = "";
    getline(cin,pathString);
    istringstream iss(pathString);
    string token;
    
    while(getline(iss,token,' ')){
        path.push_back(stoi(token));
    }

    int first = findParent(parent,path[0]-1);
    bool isConnect = true;
    for(int i = 1; i<path.size(); i++){
        if(first != findParent(parent,path[i]-1)){
            isConnect = false;
            break;
        }
    }

    if(isConnect){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    
}
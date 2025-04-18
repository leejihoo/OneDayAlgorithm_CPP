#include<iostream>
#include<string>
#include <vector>

using namespace std;

int findParent(vector<int> & parent, int target){
    if(parent[target] == target){
        return target;
    }

    return parent[target] = findParent(parent, parent[target]);
}

void unionParent(vector<int> & parent, int a, int b){
    int parentA = findParent(parent,a);
    int parentB = findParent(parent,b);

    if(parentA == parentB){
        return;
    }

    if(parentA < parentB){
        parent[parentB] = parentA;
    }
    else{
        parent[parentA] = parentB;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> parent;
    for(int i = 0; i<n+1; i++){
        parent.push_back(i);
    }

    for(int i = 0; i<m; i++){
        int command,a,b;
        cin >> command >> a >> b;
        
        if(command == 0){ // 합집합
            unionParent(parent, a, b);
        }
        else{ // command == 1 부모가 같은지 확인
            if(findParent(parent,a) == findParent(parent,b)){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
    }
}
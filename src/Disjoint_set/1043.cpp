#include<string>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int findParent(vector<int> & parent, int target){
    if(parent[target] == target){
        return target;
    }
    return parent[target] = findParent(parent,parent[target]);
}

void unionParent(vector<int> & parent, int a, int b){
    int parentA = findParent(parent,a);
    int parentB = findParent(parent,b);

    if(parentA == parentB){
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
    int N,M;
    cin >> N >> M;
    cin.ignore();

    string personKnowTrue;
    getline(cin,personKnowTrue);

    stringstream sstream(personKnowTrue);
    string temp;
    vector<int> person_true;
    while(getline(sstream,temp ,' ')){
        //cout << temp << endl;
        person_true.push_back(stoi(temp));
    }
    
    vector<vector<int>> party(M,vector<int>());
    
    for(int i = 0; i<M; i++){
        string partyInfo;
        getline(cin,partyInfo);

        stringstream sstream2(partyInfo);
        string token;
        while(getline(sstream2,token,' ')){
            party[i].push_back(stoi(token));
            //cout << token << " ";
        }
        //cout << endl;
    }

    vector<int> parent;
    
    for(int i = 0; i<N; i++){
        parent.push_back(i);
    }

    // 사람 번호 넣을 때 -1 하기 (인덱스랑 맞춰야 됨)
    for(int i = 0; i<M; i++){
        auto cur = party[i];
        int first;
        for(int j = 1; j<cur.size(); j++){
            if(j == 1){
                first = cur[j]-1;
                continue;
            }

            unionParent(parent,first,cur[j]-1);
        }
    }

    int answer = 0;
    for(int i = 0; i<M; i++){
        auto cur = party[i];
        bool isKnowTrue = false;
        for(int j = 1; j<cur.size(); j++){
            for(int k = 1; k<person_true.size(); k++){
                if(findParent(parent,person_true[k]-1) == findParent(parent,cur[j]-1)){
                    isKnowTrue  = true;
                    break;
                }
            }
            if(isKnowTrue){
                break;
            }
        }

        if(!isKnowTrue){
            answer++;
        }
    }

    cout << answer;
}
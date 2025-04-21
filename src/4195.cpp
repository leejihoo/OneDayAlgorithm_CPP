#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>

using namespace std;
int cur = 0;
vector<int> sum;
void convertStringToInt(unordered_map<string,int> & stringTointDic, string name){
    if(stringTointDic.find(name) != stringTointDic.end()){
        return;
    }
    stringTointDic[name] = cur;
    cur++;
}

int findParent(vector<int> & parent, int target){
    if(parent[target] == target){
        return target;
    }

    return parent[target] = findParent(parent,parent[target]);
}

int unionParent(vector<int> & parent, int a, int b){
    int parentA = findParent(parent, a);
    int parentB = findParent(parent, b);

    if(parentA < parentB){
        parent[parentA] = parentB;
        sum[parentB] += sum[parentA];
        return parentB;
    }
    else if(parentA > parentB){
        parent[parentB] = parentA;
        sum[parentA] += sum[parentB];
        return parentA;
    }
    else{//부모가 같은 경우
        return parentA;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    
    while(T>0){
        // 케이스 마다 전역 변수 초기화
        cur = 0;

        int F;
        cin >> F;
        unordered_map<string,int> stringTointDic;
        vector<int> parent(F,0);

        for(int i = 0; i<F; i++){
            parent[i] = i;
            sum.push_back(1);
        }

        for(int i = 0; i<F; i++){
            string first,second;
            cin >> first >> second;
            convertStringToInt(stringTointDic, first);
            convertStringToInt(stringTointDic, second);
            
            if(stringTointDic.size()>parent.size()){
                for(int i = parent.size(); i<stringTointDic.size(); i++){
                    parent.push_back(i);
                    sum.push_back(1);
                }
            }

            int targetParent = unionParent(parent,stringTointDic[first],stringTointDic[second]);

            int count = sum[targetParent];
            cout << count << "\n";
        }

        sum.clear();
        T--;
    }
}
// Connected Components in a Graph
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
bool visited[N];
vector<vector<int> >cc;
vector<int>current_cc;
void dfs(int src){
    visited[src] = true;
    current_cc.push_back(src);
    for(auto child:graph[src]){
        if(visited[child]==true) continue;
        dfs(child);
    }
}
int main(){
    int n,m;    cin >> n >> m;
    for(int i=0;i<m;i++){
        int v1,v2;  cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int cunt = 0;
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);
            cunt++;
        }
    }
    cout << cc.size() << endl;
    for(auto k:cc){
        for(auto it:k){
            cout << it << " ";
        }
        cout << endl;
    }
}
/*
8 5
1 2
2 3
2 4
3 5
6 7
output:
3(Connected Components)
1 2 3 5 4 
6 7 
8
*/
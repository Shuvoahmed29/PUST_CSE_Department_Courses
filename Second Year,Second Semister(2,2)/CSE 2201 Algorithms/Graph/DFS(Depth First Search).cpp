// DFS(Depth First Search)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int>graph[N];
bool visited[N];

void dfs(int src){
    visited[src] = true;
    cout << src << " ";
    for(auto child:graph[src]){
        if(visited[child] == true) continue;
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
    dfs(1);
}   
/*
6 9                                                             
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
DFS(1): 1 3 5 6 2 4

9 8
1 2
2 5
2 6
6 9
2 7
1 3
3 8
1 4
DFS(1): 1 2 5 6 9 7 3 8 4 
*/
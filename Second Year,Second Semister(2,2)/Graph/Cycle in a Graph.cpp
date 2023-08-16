// Cycle in a Graph
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int>graph[N];
bool visited[N];
bool dfs(int src,int parent){
    visited[src] = true;
    bool isLoopExit = false;
    for(auto child:graph[src]){
        if(visited[child]==true && child==parent) continue;
        if(visited[child]==true) return true;
        isLoopExit |= dfs(child,src);
    }
    return isLoopExit;
}
int main(){
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int v1,v2;  cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bool isLoopExit = false;
    for(int i=1;i<=n;i++){
        if(visited[i]==true) continue;
        if(dfs(i,0)){
            isLoopExit = true;
            break;
        }
    }
    cout << isLoopExit << endl;
}
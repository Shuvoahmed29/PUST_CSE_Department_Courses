#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int visited[N];
vector<int>graph[N];
void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while(!q.empty()) {
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for(int child:graph[cur]){
            if(!visited[child]){
                q.push(child);
                visited[child] = 1;
            } 
        }
    }
}
int main(){
    int n;  cin >> n;
    for(int i = 0; i < n-1; i++){
        int v1, v2; cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);
}
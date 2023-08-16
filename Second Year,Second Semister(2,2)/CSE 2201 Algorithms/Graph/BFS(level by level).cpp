#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
int visited[N];
int level[N];
void bfs(int source){
    queue<int>q;
    q.push(source);
    visited[source]=1;
    while(!q.empty()){
        int q_cur = q.front();
        cout << q_cur <<" ";
        q.pop();
        for(int child:graph[q_cur]){
            if(!visited[child]){
                q.push(child);
                visited[child]=1;
                level[child]=level[q_cur]+1;
            }
        }
    }
}
int main(){
    int n;  cin >> n;
    for(int i = 0; i < n-1; i++){
        int v1,v2;  cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);
    for(int i = 0; i <=n; i++){
        cout << i << ": " << level[i] << endl;
    }
}
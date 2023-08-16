#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
const int N = 1e5+9;
vector<vector<int>>g[N];
vector<int> dist(N),parent(N);
bool vis[N];
const int INF = 1e9;

int primsMST(int src,int n){
	int cost = 0;
    for(int i=0;i<n;i++){
        dist[i] = INF;
    }
    set<pair<int,int>> s;
    dist[src] =  0;
    s.insert({0,src});// wt,vertex

    while(!s.empty()){
        auto x = *s.begin();
        s.erase(x);
        int w = x.first;
        int u = x.second;
        vis[u] = true;
        int v = parent[u];
        cout << u << " " << v <<" "<< w << endl;
        cost += w;
        for(auto it:g[u]){
        	int v1 = it[0];
        	int wt = it[1];
            if(vis[v1] == true) continue;
            if(dist[v1] > wt){
                s.erase({dist[v1],v1});
                dist[v1] = wt;
                s.insert({dist[v1],v1});
                parent[v1] = u;
            }
        }
    }
    return cost;
}
int main(){
	code();
    int n,m;	cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;  cin >> u >> v >>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int cost = primsMST(0,n);
    cout << cost << endl;
}
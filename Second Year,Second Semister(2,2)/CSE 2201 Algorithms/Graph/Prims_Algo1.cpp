#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
const int N = 1e5+9;
vector<vector<int>> graph[N];
const int INF = 1e9;
vector<int> dist(N),parent(N);
bool vis[N];
int prims(int src,int n){
	int total = 0;
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	set<vector<int>> st;
	dist[src] = 0;
	st.insert({0,src}); // wt,vertex
	cout << "Connected Edges!\n";
	while(!st.empty()){
		auto x = *st.begin();
		st.erase(x);
		int w = x[0];
		int u = x[1];
		int v = parent[u];
		vis[u] = true;
		total += w;
		cout << u << " " << v <<" " << w << endl;
		for(auto it:graph[u]){
			int v = it[0];
			int wt = it[1];
			if(vis[v] == true) continue;
			if(dist[v]>wt){
				st.erase({dist[v],v});
				dist[v] = wt;
				st.insert({dist[v],v});
				parent[v] = u;
			}
		}
	}
	return total;
}
int main(){
	code();
	int n,m;	cin >> n >> m;
	for(int i=0;i<m;i++){
		int v1,v2,wt;	cin >> v1 >> v2 >> wt;
		graph[v1].push_back({v2,wt});
		graph[v2].push_back({v1,wt});
	}
	int cost = prims(0,n);
	cout << "Total Cost: " << cost << endl;
}

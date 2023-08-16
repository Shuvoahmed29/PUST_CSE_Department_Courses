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
const int INF = 1e9+9;
vector<int>dist(N),parent(N);
bool visited[N];
int prims(int src,int n){
	int cost = 0;
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	dist[src] = 0;
	set<pair<int,int>>st;
	st.insert({0,src});//wt,vertex;
	cout << "Connected Edges!\n";
	while(!st.empty()){
		auto x = *st.begin();
		st.erase(x);
		int wt = x.first;
		int u = x.second;
		int v = parent[u];
		visited[u] = true;
		cost += wt;
		cout << v << " " << u << " " << wt << endl;
		for(auto it:graph[u]){
			int v = it[0];
			int w = it[1];
			if(visited[v] == true) continue;
			if(dist[v] > w){
				st.erase({dist[v],v});
				dist[v] = w;
				st.insert({dist[v],v});
				parent[v] = u;
			}
		}
	}
	return cost;
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
	cout << "\nTotal Cost: " << cost << endl;
}

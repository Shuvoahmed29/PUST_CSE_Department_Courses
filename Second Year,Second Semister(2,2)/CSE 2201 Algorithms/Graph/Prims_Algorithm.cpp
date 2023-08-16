#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int n,m;
const int N = 1e5+9;
vector<vector<int>> graph[N];
bool ok[N];
vector<int> parent(N),dist(N);
const int INF = 1e9;
int cost = 0;
void prims(int src){
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	set<vector<int>> s;
	dist[src] = 0;
	s.insert({0,src}); // wt,vertex;
	cout << "Connected Edges!\n";
	while(!s.empty()){
		auto x = *(s.begin());
		s.erase(x);
		ok[x[1]] = true;
		int u = x[1];
		int v = parent[x[1]];
		int w = x[0];
		cout << u << " " << v << " " <<w << endl;
		cost += w;
		for(auto it:graph[x[1]]){
			if(ok[it[0]] == true)	continue;
			if(dist[it[0]]>it[1]){
				s.erase({dist[it[0]],it[0]});
				dist[it[0]] = it[1];  
				s.insert({dist[it[0]],it[0]});
				parent[it[0]] = x[1];
			}
		}
	}
}
int main(){
	code();
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v,w;	cin >> u >> v >> w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	prims(1);
	cout << "Total Cost : "<< cost << endl;
}
